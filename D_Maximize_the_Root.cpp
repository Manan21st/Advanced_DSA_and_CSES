#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int dfs(vector<vector<int>>& adj,int n,vector<int>& arr,int node){
    if(adj[node].size()==0){
        return arr[node];
    }
    int sum = LLONG_MAX;
    for(auto child:adj[node]){
        sum = min(sum,dfs(adj,n,arr,child));
    }
    return (arr[node]+sum);
}

int solve(vector<vector<int>> adj,int n,vector<int>& arr){
    int ans = LLONG_MAX;
    ans = dfs(adj,n,arr,1);
    return ans;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int n;
        cin >> n;
        vector<int> arr(n+1);
        for(int i=1;i<=n;++i){
            cin >> arr[i];
        }
        vector<vector<int>> adj(n+1);
        for(int i=2;i<=n;++i){
            int pi;
            cin >> pi;
            adj[pi].push_back(i);
        }
        int ans = solve(adj,n,arr);
        cout << ans << endl;
    }
    return 0;
}
