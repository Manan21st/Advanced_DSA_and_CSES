#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

class DSU{
public:
    vector<int> parent,size;
    stack<vector<int>> operations;
    int n;
    DSU(int n){
        this->n = n;
        parent.resize(n,0);
        size.resize(n,1);
        for(int i=0;i<n;++i){
            parent[i] = i;
        }
    }
    int find(int x){
        if(parent[x]==x){
            return x;
        }
        return find(parent[x]);
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
        operations.push({a,b,size[a],size[b]});
        parent[b] = a;
        size[a]+=size[b];
        n--;
    }

    void persist(){
        operations.push({-1});
    }

    void rollback(){
        while(operations.size() and operations.top()[0]!=-1){
            auto diff = operations.top();
            operations.pop();
            int a = diff[0], b = diff[1], sizea = diff[2], sizeb = diff[3];
            parent[a] = a;
            size[a] = sizea;
            parent[b] = b;
            size[b] = sizeb;
            n++;
        }
        operations.pop();
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
                cout << dsu.n << endl;
            }else if(type=="persist"){
                dsu.persist();
            }else{
                dsu.rollback();
                cout << dsu.n << endl;
            }
        }
    }
    return 0;
}