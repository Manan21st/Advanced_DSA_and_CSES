#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(int node, int parent, int dist, vector<vector<int>>& adj){
    if(dist==0){
        return 1;
    }
    int ans=0;
    for(int v : adj[node]){
        if(v==parent){
            continue;
        }
        ans+=solve(v,node,dist-1,adj);
    }
    return ans;
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test=1;
    // cin>>test;
    for(int t =0;t<test;++t){
        int n,k;
        cin >> n >> k;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n-1;++i){
            int u,v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int ans=0;
        for(int i=1;i<=n;++i){
            ans+=solve(i,-1,k,adj);
        }
        cout << ans/2 << endl;
    }
    return 0;
}