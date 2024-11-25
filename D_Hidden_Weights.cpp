#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

void dfs(int node, vector<vector<pair<int,int>>>& adj, vector<bool>& visited, vector<int>& ans){
    visited[node] = true;
    for(auto next : adj[node]){
        if(!visited[next.first]){
            ans[next.first] = ans[node]+next.second;
            dfs(next.first,adj,visited,ans);
        }
    }
}

vector<int> solve(vector<vector<pair<int,int>>>& adj, int n){
    vector<int> ans(n+1,0);
    vector<bool> visited(n+1,false);
    for(int i=1;i<=n;++i){
        if(!visited[i]){
            dfs(i,adj,visited,ans);
        }
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
        int n,m;
        cin >> n >> m;
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<m;++i){
            int u,v,w;
            cin >> u >> v >> w;
            adj[u].push_back({v,w});
            adj[v].push_back({u,-w});
        }
        vector<int> ans = solve(adj,n);
        for(int i=1;i<ans.size();++i){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}