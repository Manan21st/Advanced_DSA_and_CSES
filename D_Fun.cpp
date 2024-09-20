#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

int solve(int n, int x){
    int ans=0;
    for(int i=1;i<=x;++i){
        for(int j=1;j<=min(x-i,n/i);++j){
            int c = min(x-i-j,(n-(i*j))/(i+j));
            if(c>0){
                ans+=c;
            }
        }
    }
    return ans;
}

signed main(){
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int n,x;
        cin >> n >> x;
        cout<<solve(n,x)<<endl;
    }
    return 0;
}
