#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

int modInv(int a,int b){
    if(b==0){
        return 1;
    }
    if(b%2==0){
        int x = modInv(a,b/2);
        return (x*x)%mod;
    }
    return (a*modInv(a,b-1))%mod;
}

int solve(int n, map<char,int>& mp, vector<int>& fact, vector<int>& factInv){
    int ans=fact[n]%mod;
    for(auto x:mp){
        ans = (ans*factInv[x.second])%mod;
    }
    return ans%mod;
}

signed main(){

    vector<int> fact(1000001,1), factInv(1000001,1);
    for(int i =1;i<1000001;i++){
        fact[i] = (fact[i-1]*i)%mod;
        factInv[i] = modInv(fact[i],mod-2);
    }

    string s;
    cin >> s;

    map<char,int> mp;
    for(int i =0;i<s.size();i++){
        mp[s[i]]++;
    }

    cout << solve(s.size(), mp,fact,factInv) << endl;

    return 0;
}
