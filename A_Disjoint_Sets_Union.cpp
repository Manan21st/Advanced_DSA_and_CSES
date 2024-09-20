#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

class DSU{
public:
    vector<int> parent;
    int n;
    DSU(int n){
        this->n = n;
        parent.resize(n,0);
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
            return ;
        }
        parent[b] = a;
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
            int u,v;
            cin >> u >> v;
            u--,v--;
            if(type=="union"){
                dsu.unite(u,v);
            }else{
                if(dsu.find(u)==dsu.find(v)){
                    cout << "YES" << endl;
                }else{
                    cout << "NO" << endl;
                }
            }
        }
    }
    return 0;
}