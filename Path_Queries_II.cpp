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

    SegmentTree(int n,T identity){
        N = n;
        this->identity = identity;
        tree.assign(4*N,identity);
    }

    T merge(T a, T b){
        return max(a,b);
    }

    void update(int l, int r, T val){
        function<void(int,int,int)> func = [&](int tIdx,int tLeft, int tRight){
            if(r<tLeft or l>tRight){
                return;
            }
            if(l<=tLeft and tRight<=r){
                tree[tIdx] = val;
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
    for(auto child: adj[node]){
        if(child != parent){
            dfs(child, node, adj, euler, in, out, timer);
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
        for(int i=0;i<n;++i){
            cin>>values[i];
        }
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;++i){
            int u,v;
            cin >> u >> v;
            u--,v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> euler,in(n),out(n);
        int timer = 0ll;
        dfs(0,-1,adj,euler,in,out,timer);

        SegmentTree<int> st(euler.size(),0);
        for(int i=0;i<n;++i){
            int inTime = in[i];
            int outTime = out[i];
            st.update(inTime,inTime,values[i]);
            st.update(outTime,outTime,values[i]);
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
                st.update(inTime,inTime,val);
                st.update(outTime,outTime,val);
            }else{
                int l,r;
                cin >> l >> r;
                l--,r--;
                cout << in[l] << " " << in[r] << endl;
                cout << st.query(in[l],in[r]) << endl;
            }
        }
    }
    return 0;
}