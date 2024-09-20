#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

bool isEdge(int u,int v,vector<vector<int>>& adj){
    for(auto x:adj[u]){
        if(x==v){
            return true;
        }
    }
    return false;
}

int calc(int n, vector<vector<int>>& adjG,vector<vector<int>>& adjH, vector<vector<int>>& cost, vector<int>& perm){
    int res =0;
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            if(isEdge(i,j,adjG)!=isEdge(perm[i],perm[j],adjH)){
                res+=cost[i][j];
            }   
        }   
    }
    return res;
}

void solve(int x,int n,int& ans,vector<int>& perm,vector<vector<int>>& adjG,vector<vector<int>>& adjH, vector<vector<int>>& cost){
    if(x==n){
        ans = min(ans,calc(n,adjG,adjH,cost,perm));
        return;
    }
    for(int i=x;i<n;++i){
        swap(perm[x],perm[i]);
        solve(x+1,n,ans,perm,adjG,adjH,cost);
        swap(perm[x],perm[i]);
    }
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test=1;
    // cin>>test;
    for(int t =0;t<test;++t){
        int n,g,h;
        cin >> n >> g >> h;
        vector<vector<int>> adjG(n);
        vector<vector<int>> adjH(n);
        for(int i=0;i<g;++i){
            int u,v;
            cin >> u >> v;
            u--,v--;
            adjG[u].push_back(v);
            adjG[v].push_back(u);
        }
        for(int i=0;i<h;++i){
            int u,v;
            cin >> u >> v;
            u--,v--;
            adjH[u].push_back(v);
            adjH[v].push_back(u);
        }
        vector<vector<int>> cost(n,vector<int> (n));
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                cin >> cost[i][j];
            }
        }
        vector<int> perm(n);
        for(int i=0;i<n;++i){
            perm[i]=i;
        }
        int ans = LLONG_MAX;
        solve(0,n,ans,perm,adjG,adjH,cost);
        cout << ans << endl;
    }
    return 0;
}