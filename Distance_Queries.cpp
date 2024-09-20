#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

class TreeAncestor {
public:
    vector<vector<int>> dp;
    TreeAncestor(int n, vector<int>& parent) {
        dp = vector<vector<int>> (32,vector<int> (n));
        dp[0]=parent;
        for(int i=1;i<32;++i){
            for(int j =0;j<n;++j){
                int halfway = dp[i-1][j];
                if(halfway==-1){
                    dp[i][j]=-1;
                }else{
                    dp[i][j] = dp[i-1][halfway];
                }
            }
        }
    }

    int query(int node,int k){
        for(int i=30;i>=0;--i){
            if(k&(1<<i)){
                node = dp[i][node];
                if(node==-1){
                    return -1;
                }
            }
        }
        return node;
    }
};


signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test=1;
    // cin>>test;
    for(int t =0;t<test;++t){
        int n,q;
        cin >> n >> q;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n-1;++i){
            int u,v;
            cin >> u >> v;
            u--,v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> parent(n);
        vector<int> level(n,0);
        function<void(int,int,int)> dfs = [&](int node, int l, int par){
            level[node] = l;
            parent[node] = par;
            for(auto child: adj[node]){
                if(child!=par){
                    dfs(child, l+1, node);
                }
            }
        };
        dfs(0,0,-1);

        TreeAncestor ta(n, parent);
        function<int(int,int)> query = [&](int x, int y){
            if(level[x]<level[y]){
                swap(x,y);
            }
            if(level[x]!=level[y]){
                x = ta.query(x, level[x]-level[y]);
            }
            if(x==y){
                return x;
            }

            for(int i=30;i>=0;--i){
                int x_new = ta.dp[i][x];
                int y_new = ta.dp[i][y];
                if(x_new!=y_new){
                    x = x_new;
                    y = y_new;
                }
            }
            return ta.dp[0][x];
        };

        for(int i=0;i<q;++i){
            int u,v;
            cin >> u >> v;
            u--,v--;
            int dist = level[u] + level[v] - 2*level[query(u,v)];
            cout << dist << endl;
        }
    }
    return 0;
}