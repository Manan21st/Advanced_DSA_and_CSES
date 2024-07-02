#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

int dp[100][2][4];

ll solve(int pos, bool tight, string& s,int k){
    if(pos==s.size()){
        return k==0;
    }
    if(dp[pos][tight][k]!=-1){
        return dp[pos][tight][k];
    }
    int min =0;
    int max = tight ? s[pos]-'0' : 9;
    ll ans = 0;
    for(int i =min;i<=max;i++){
        bool newTight = tight & (i==max);
        if(i==0){
            ans+=solve(pos+1,newTight,s,k);
        }
        else if(k>0){
            ans+=solve(pos+1,newTight,s,k-1);
        }
        
    }
    return dp[pos][tight][k] = ans;
}

int main(){
    memset(dp,-1,sizeof dp);
    string s;
    int k;
    cin >> s >> k;
    cout << solve(0,1,s,k) << endl;
    return 0;
}
