#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

class DSU{
public:
    vector<int> parent, size, minimum, maximum;
    int n;
    DSU(int n){
        this->n = n;
        parent.resize(n,0);
        size.resize(n,1);
        minimum.resize(n,0);
        maximum.resize(n,0);
        for(int i=0;i<n;++i){
            parent[i] = i;
            minimum[i] = i;
            maximum[i] = i;
        }
    }

    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v){
        int a = find(u);
        int b = find(v);
        if(a==b){
            return;
        }
        if(size[a]<size[b]){
            swap(a,b);
        }
        parent[b] = a;
        size[a] += size[b];
        minimum[a] = min(minimum[a],minimum[b]);
        maximum[a] = max(maximum[a],maximum[b]);
    }
};

int solve(){
    return 0;
}

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
            string type;
            cin>>type;
            if(type=="union"){
                int u,v;
                cin>>u>>v;
                u--,v--;
                dsu.unite(u,v);
            }else{
                int node;
                cin>>node;
                node--;
                int a = dsu.find(node);
                cout << dsu.minimum[a]+1 << " " << dsu.maximum[a]+1 << " "<< dsu.size[a] << endl;
            }
        }
    }
    return 0;
}