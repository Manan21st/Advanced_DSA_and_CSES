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
        return a+b;
    }

    void update(int qIdx, T val){
        function<void(int,int,int)> func = [&](int tIdx,int tLeft, int tRight){
            if(tLeft == tRight){
                tree[tIdx] += val;
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

void dfs(int node, int parent, vector<vector<int>>& adj, vector<int>& euler, vector<int>& in , vector<int>& out, int& timer, vector<int>& level){
    in[node] = timer++;
    euler.push_back(node);
    level[node] = parent==-1 ? 0 : level[parent]+1;
    for(int v : adj[node]){
        if(v==parent){
            continue;
        }
        dfs(v,node,adj,euler,in,out,timer,level);
    }
    euler.push_back(node);
    out[node] = timer++;
}


signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test=1;
    // cin>>test;
    for(int t =0;t<test;++t){
        int n,q;
        cin>>n>>q;
        vector<int> weights(n);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;++i){
            cin>>weights[i];
        }
        for(int i=0;i<n-1;++i){
            int u,v;
            cin>>u>>v;
            u--,v--;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> in(n),out(n),level(n,0),euler;
        int timer = 0ll;
        dfs(0,-1,adj,euler,in,out,timer,level);

        SegmentTree<int> odd(2*n,0ll), even(2*n,0ll);

        for(int i=0;i<q;++i){
            int type;
            cin >> type;
            if(type==1){
                int idx,val;
                cin>>idx>>val;
                idx--;
                int l = in[idx];
                int r = out[idx];
                if(level[idx]%2==1){
                    odd.update(l,val);
                    odd.update(r+1,-val);
                    even.update(l,-val);
                    even.update(r+1,val);
                }else{
                    even.update(l,val);
                    even.update(r+1,-val);
                    odd.update(l,-val);
                    odd.update(r+1,val);
                }
            }else{
                int node;
                cin>>node;
                node--;
                int ans = weights[node];
                if(level[node]%2==1){
                    ans+=odd.query(0,in[node]);
                }else{
                    ans+=even.query(0,in[node]);
                }
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}