#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(int n, int m, int k, vector<int>& weights){
    int ans =0;
    vector<int> mult;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            int r=min(i,n-k+1)-max(0ll,i-k);
            int c=min(j,m-k+1)-max(0ll,j-k);
            mult.push_back(r*c);
        }
    }
    sort(mult.begin(),mult.end(),greater<int>());
    sort(weights.begin(),weights.end(),greater<int>());
    for(int i =0;i<weights.size();++i){
        ans += (mult[i]*weights[i]);
    }
    return ans;
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int n,m,k,w;
        cin >> n >> m >> k >> w;
        vector<int> weights(w);
        for(int i =0;i<w;++i){
            cin >> weights[i];
        }
        cout << solve(n,m,k,weights) << endl;
    }
    return 0;
}
