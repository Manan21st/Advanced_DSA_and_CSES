#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long dp[20][10][2][2];

long long solve(long long pos,long long prev,long long leadingZeroes,bool tight, string num){
    if(pos==num.length()){
        return 1;
    }
    if(dp[pos][prev][leadingZeroes][tight]!=-1){
        return dp[pos][prev][leadingZeroes][tight];
    }
    long long ans=0;
    long long limit= (tight?num[pos]-'0':9);
    for(long long i=0;i<=limit;i++){
        if (leadingZeroes || i != prev) {
            ans += solve(pos + 1, i, leadingZeroes && i == 0, tight && i == limit, num);
        }
    }
    return dp[pos][prev][leadingZeroes][tight]=ans;
}   

int main(){
    long long a,b;
    cin>>a>>b;
    memset(dp,-1,sizeof(dp));
    long long ans1=0;
    if(a!=0){
        ans1=solve(0,0,1,1,to_string(a-1));
    }
    memset(dp,-1,sizeof(dp));
    long long ans2=solve(0,0,1,1,to_string(b));
    cout<<ans2-ans1<<endl;
    return 0;
}