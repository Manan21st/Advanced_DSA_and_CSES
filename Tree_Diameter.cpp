#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

void solve(int node, int parent, vector<int>& dist, vector<vector<int>>& adj){
    for(int v : adj[node]){
        if(v!=parent){
            dist[v] = dist[node]+1;
            solve(v,node,dist,adj);
        }
    }
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test=1;
    // cin>>test;
    for(int t =0;t<test;++t){
        int n;
        cin >> n;
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;++i){
            int u,v;
            cin >> u >> v;
            u--, v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> dist(n);
        solve(0,-1,dist,adj);
        int maxDist = 0;
        int maxNode = 0;
        for(int i=0;i<n;++i){
            if(dist[i]>maxDist){
                maxDist = dist[i];
                maxNode = i;
            }
        }
        dist.assign(n,0);
        solve(maxNode,-1,dist,adj);
        maxDist = 0;
        for(int i=0;i<n;++i){
            maxDist = max(maxDist,dist[i]);
        }
        cout<<maxDist<<endl;
    }
    return 0;
}