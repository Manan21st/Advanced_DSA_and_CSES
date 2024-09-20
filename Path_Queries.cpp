#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

void dfs(int node, int par, vector<vector<int>>& adj, vector<int>& euler, vector<int>& tin, vector<int>& tout, int& timer){
    tin[node] = timer++;
    euler.push_back(node);
    for(auto v: adj[node]){
        if(v!=par){
            dfs(v, node, adj, euler, tin, tout, timer);
        }
    }
    tout[node] = timer++;
    euler.push_back(node);
}

template<typename T>
class SegmentTree{
public:
    int N;
    T identity;
    vector<T> tree;

    SegmentTree(int n,T identity){
        N = n;
        this->identity = identity;
        tree.assign(4*N,identity);
    }

    T merge(T a, T b){
        return a+b;
    }

    void update(int qIdx, T val){
        function<void(int,int,int)> func = [&](int tIdx,int tLeft, int tRight){
            if(tLeft == tRight){
                tree[tIdx] = val;
                return;
            }

            int tMid = tLeft + (tRight-tLeft)/2;
            if(tLeft<=qIdx and qIdx<=tMid){
                func(2*tIdx+1,tLeft,tMid);
            }else{
                func(2*tIdx+2,tMid+1,tRight);
            }

            tree[tIdx] = merge(tree[2*tIdx+1],tree[2*tIdx+2]);
        };
        func(0,0,N-1);
    }

    T query(int l, int r){
        function<T(int,int,int)> func = [&](int tIdx, int tLeft, int tRight){
            // no overlap
            if(r<tLeft or l>tRight){
                return identity;
            }

            // complete overlap
            if(l<=tLeft and tRight<=r){
                return tree[tIdx];
            }

            // partial overlap
            int tMid = tLeft + (tRight-tLeft)/2;
            return merge(func(2*tIdx+1,tLeft,tMid),func(2*tIdx+2,tMid+1,tRight));
        };
        return func(0,0,N-1);
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
        cin>>n>>q;
        vector<int> weights(n+1);
        for(int i=1;i<=n;++i){
            cin>>weights[i];
        }
        vector<vector<int>> adj(n+1);
        for(int i=0;i<n-1;++i){
            int u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> euler;
        vector<int> tin(n+1);
        vector<int> tout(n+1);
        int timer = 0ll;
        dfs(1,0,adj,euler,tin,tout,timer);

        SegmentTree<int> st(euler.size(), 0ll);
        for(int i=1;i<=n;++i){
            int node = i;
            int idx1 = tin[node];
            st.update(idx1, weights[node]);
            int idx2 = tout[node];
            st.update(idx2, -weights[node]);
        }

        for(int i=0;i<q;++i){
            int type;
            cin>>type;
            if(type==1){
                int node, w;
                cin>>node>>w;
                int idx1 = tin[node];
                st.update(idx1, w);
                int idx2 = tout[node];
                st.update(idx2, -w);
            }
            else{
                int node;
                cin>>node;
                int idx = tin[node];
                cout << st.query(0, idx) << endl;
            }
        }
    }
    return 0;
}