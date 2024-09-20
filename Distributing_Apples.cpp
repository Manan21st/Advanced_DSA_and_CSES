#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;


int solve(int a, int b,vector<int>& fact,vector<int>& factInv){
    int x =fact[a];
    int y = factInv[b];
    int z = factInv[a-b];
    int ans = (x*y)%mod;
    ans = (ans*z)%mod;      
    return ans;
}

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


signed main(){
    
    vector<int> fact(2000001,1), factInv(2000001,1);
    for(int k =1;k<2000001;k++){
        fact[k] = (fact[k-1]*k)%mod;
        factInv[k] = modInv(fact[k],mod-2);
    }
    int n,r;
    cin >> r >> n;    
    cout << solve(n+r-1,r-1,fact,factInv) << endl;
    return 0;
}