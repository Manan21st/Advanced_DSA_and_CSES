#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

int dp[10001][2][101];

ll solve(int pos, bool tight, string& s,int sum, int d){
    if(pos==s.size()){
        return sum%d==0;
    }
    if(dp[pos][tight][sum]!=-1){
        return dp[pos][tight][sum];
    }
    int min = 0;
    int max = tight ? s[pos]-'0' : 9;
    ll ans = 0;
    for(int i = min;i<=max;i++){
        bool newTight = tight & (i==max);
        ans+=solve(pos+1,newTight,s,(sum+i)%d,d);
        ans%=mod;
    }
    return dp[pos][tight][sum] = ans%mod;
}

int main(){
    memset(dp,-1,sizeof dp);
    string s;
    int d;
    cin >> s >> d;
    cout << ((solve(0,1,s,0,d) - 1)+mod)%mod << endl;
    return 0;
}
