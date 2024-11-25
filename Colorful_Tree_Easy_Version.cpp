#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& dist){
    dist[node] = (parent==-1) ? 0 : dist[parent]+1;
    for(auto child: adj[node]){
        if(child!=parent){
            dfs(child,node,adj,dist);
        }
    }
}

int solve(int n, vector<vector<int>>& adj){

    return 0;
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int n;
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;++i){
            int u,v;
            cin>>u>>v;
            u--;v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

    }
    return 0;
}