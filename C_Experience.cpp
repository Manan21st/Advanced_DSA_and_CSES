#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

class DSU{
public:
    vector<int> parent, size, points;
    int n;
    DSU(int n){
        this->n = n;
        parent.resize(n,0);
        size.resize(n,1);
        points.resize(n,0);
        for(int i=0;i<n;++i){
            parent[i] = i;
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
        size[a]+=size[b];
        points[b]-=points[a];
    }
    
    void add(int x, int pts){
        int a = find(x);
        points[a]+=pts;
    }

    int get(int x){
        if(parent[x]==x){
            return points[x];
        }
        int temp = points[parent[x]];
        return temp + get(parent[x]);
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
        DSU dsu(n);
        for(int i=0;i<q;++i){
            string type;
            cin >> type;
            if(type=="join"){
                int u, v;
                cin >> u >> v;
                u--,v--;
                dsu.unite(u,v);
            }else if(type=="add"){
                int x, pts;
                cin >> x >> pts;
                x--;
                dsu.add(x,pts);
            }else{
                int x;
                cin >> x;
                x--;
                cout << dsu.get(x) << endl;
            }
        }
    }
    return 0;
}