#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

vector<int> solve(vector<vector<pair<int,int>>>& graph, vector<int>& nodeWeight, int n, int m){
    vector<int> dist(n+1,LLONG_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist[1] = nodeWeight[1];
    pq.push({dist[1], 1});
    while (!pq.empty()) {
        auto [current_dist, u] = pq.top();
        pq.pop();
        if (current_dist > dist[u]) continue;
        for (auto &[v, weight] : graph[u]) {
            int new_dist = current_dist + weight + nodeWeight[v];
            if (new_dist < dist[v]) {
                dist[v] = new_dist;
                pq.push({new_dist, v});
            }
        }
    }
    return dist;
}

signed main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> graph(n+1);
    vector<int> nodeWeight(n+1);
    for(int i =1;i<=n;i++){
        cin >> nodeWeight[i];
    }
    for(int i =0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    vector<int> ans = solve(graph,nodeWeight,n,m);
    for(int i =2;i<=n;i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
