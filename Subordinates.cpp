#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

void solve(int node, vector<int>& sub,vector<vector<int>>& adj){
    for(auto next: adj[node]){
        solve(next,sub,adj);
        sub[node]+=(sub[next]+1);
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
        for(int i=1;i<n;++i){
            int x;
            cin >> x;
            x--;
            adj[x].push_back(i);
        }
        vector<int> sub(n,0);
        solve(0,sub,adj);
        for(int i=0;i<n;++i){
            cout << sub[i] << " ";
        }
        cout << endl;
    }
    return 0;
}