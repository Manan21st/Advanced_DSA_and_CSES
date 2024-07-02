#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//for checking sum of digits of a number

int dp[18][18*9+1];

int solve(int pos,int n,int sum){
    if(pos==n){
        if(sum==10){
            return 1;
        }
        return 0;
    }

    if(dp[pos][sum]!=-1){
        return dp[pos][sum];
    }

    int ans = 0;
    for(int i =0;i<=9;i++){
        ans+=solve(pos+1,n,sum+i);
    }
    return dp[pos][sum] = ans;
}
int main(){
    memset(dp,-1,sizeof(dp));
    cout<< solve(0,4,0) << endl;
    return 0;
}