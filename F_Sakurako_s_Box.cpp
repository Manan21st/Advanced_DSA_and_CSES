#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

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


int solve(vector<int>& arr){
    int n = arr.size();
    int sum = 0;
    int squaredSum = 0;
    for(int i=0;i<n;++i){
        sum = (sum+arr[i])%mod;
        squaredSum = (squaredSum + (arr[i]*arr[i])%mod)%mod;
    }
    int p = ((sum*sum)%mod - (squaredSum)%mod + mod)%mod;
    int q = modInv(n*(n-1)%mod,mod-2);
    int ans = (p*q)%mod;
    return ans;
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0;i<n;++i){
            cin >> arr[i];
        }
        
        cout << solve(arr) << endl;
    }
    return 0;
}