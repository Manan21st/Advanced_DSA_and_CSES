#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

class DSU{
public:
    vector<int> parent, dist;
    int n;
    DSU(int n){
        parent.resize(n,0);
        dist.resize(n,0);
        for(int i=0;i<n;++i){
            parent[i] = i;
        }
    }
    pair<int,int> find(int x){
        if(parent[x]==x){
            return {x,0};
        }
        auto[root,d] = find(parent[x]);
        parent[x]=root;
        dist[x]+=d;
        return {parent[x],dist[x]};
    }

    void unite(int u, int v){
        parent[u] = v;
        dist[u] = 1;
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
        DSU dsu(n);
        for(int i=0;i<q;++i){
            int type;
            cin>>type;
            if(type==1){
                int u,v;
                cin >> u >> v;
                u--,v--;
                dsu.unite(u,v);
            }else{
                int c;
                cin >> c;
                c--;
                cout << dsu.find(c).second << endl;
            }
        }   
    }
    return 0;
}

