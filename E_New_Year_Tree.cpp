#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

template<typename T>
class SegmentTree{
public:
    int N;
    T identity;
    vector<T> tree;
    vector<bool> lazy;
    vector<int> lazyVal; 

    SegmentTree(int n,T identity){
        N = n;
        this->identity = identity;
        tree.assign(4*N,identity);
        lazy.assign(4*N,false);
        lazyVal.assign(4*N,0);
    }

    T merge(T a, T b){
        return a|b;
    }

    void propogate(int tIdx, int tL, int tR){
        if(!lazy[tIdx]){
            return;
        }
        if(tL<tR){
            lazy[2*tIdx+1] = true;
            lazy[2*tIdx+2] = true;
            lazyVal[2*tIdx+1] = lazyVal[tIdx];
            lazyVal[2*tIdx+2] = lazyVal[tIdx];
        }
        tree[tIdx] = lazyVal[tIdx];
        lazy[tIdx] = false;
        lazyVal[tIdx] = 0;
    }

    void update(int l, int r, T val){
        function<void(int,int,int)> func = [&](int tIdx,int tLeft, int tRight){
            propogate(tIdx,tLeft,tRight);
            if(r<tLeft or l>tRight){
                return;
            }
            if(l<=tLeft and tRight<=r){
                lazy[tIdx] = true;
                lazyVal[tIdx] = val;
                propogate(tIdx,tLeft,tRight);
                return;
            }
            int tMid = tLeft + (tRight-tLeft)/2;
            func(2*tIdx+1,tLeft,tMid);
            func(2*tIdx+2,tMid+1,tRight);
            tree[tIdx] = merge(tree[2*tIdx+1],tree[2*tIdx+2]);
        };
        func(0,0,N-1);
    }

    T query(int l, int r){
        function<T(int,int,int)> func = [&](int tIdx, int tLeft, int tRight){
            propogate(tIdx,tLeft,tRight);
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

void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& euler, vector<int>& in, vector<int>& out, int& timer){
    in[node] = timer++;
    euler.push_back(node);
    for(auto v: adj[node]){
        if(v!=parent){
            dfs(v, node, adj, euler, in, out, timer);
        }
    }
    euler.push_back(node);
    out[node] = timer++;
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test=1;
    // cin>>test;
    for(int t =0;t<test;++t){
        int n,q;
        cin >> n >> q;
        vector<int> values(n);
        vector<vector<int>> adj(n);
        for(int i =0;i<n;++i){
            cin >> values[i];
        }

        for(int i=0;i<n-1;++i){
            int u,v;
            cin >> u >> v;
            u--,v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> euler;
        vector<int> in(n,0);
        vector<int> out(n,0);
        int timer=0ll;
        dfs(0,-1,adj,euler,in,out,timer);

        
        SegmentTree<int> st(euler.size(),0ll);
        for(int i=0;i<n;++i){
            int inTime = in[i];
            int outTime = out[i];
            st.update(inTime, inTime, (1ll<<values[i]));
            st.update(outTime, outTime, (1ll<<values[i]));
        }

        for(int i=0;i<q;++i){
            int type;
            cin >> type;
            if(type==1){
                int idx,val;
                cin >> idx >> val;
                idx--;
                int inTime = in[idx];
                int outTime = out[idx];
                st.update(inTime, outTime, (1ll<<val));
            }else{
                int idx;
                cin >> idx;
                idx--;
                int query = st.query(in[idx], out[idx]);
                int ans =0;
                for(int i=61;i>=0;--i){
                    if(query&(1ll<<i)){
                        ans++;
                    }
                }
                cout << ans << endl;
            }
        }
    }
    return 0;
}