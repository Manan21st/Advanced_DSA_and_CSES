#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

int solve(int n, int k, vector<int>& a, vector<int>& b){
    int ans=0;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<n and k>0;++i){
        int value = a[i]/b[i];
        if(value>k){
            value =k;
        }
        ans+=(value*a[i])%mod;
        k-=value;
        a[i]-=value*b[i];
        if(a[i]>0){
            ans+=a[i]%mod;
        }
    }
    return ans;

}

signed main(){
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int n,k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0;i<n;++i){
            cin>>a[i];
        }
        for(int i=0;i<n;++i){
            cin>>b[i];
        }
        cout<<solve(n,k,a,b)<<endl;
    }
    return 0;
}
