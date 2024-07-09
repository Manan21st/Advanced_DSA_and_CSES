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

int solve(int a, int b,vector<int>& fact,vector<int>& factInv){
    int x =fact[a];
    int y = factInv[b];
    int z = factInv[a-b];
    int ans = (x*y)%mod;
    ans = (ans*z)%mod;
    return ans;
}

signed main(){
    int n;
    cin >> n;
    vector<int> fact(1000001,1), factInv(1000001,1);
    for(int k =1;k<1000001;k++){
        fact[k] = (fact[k-1]*k)%mod;
        factInv[k] = modInv(fact[k],mod-2);
    }
    for(int i =0;i<n;i++){
        int a,b;
        cin >> a >> b;
        cout << solve(a,b,fact,factInv) << endl;
    }
    return 0;
}