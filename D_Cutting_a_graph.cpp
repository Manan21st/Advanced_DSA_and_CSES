#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

class DSU{
public:
    vector<int> parent,size;
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
        int n,m,k;
        cin>>n>>m>>k;
        DSU dsu(n);
        for(int i=0;i<m;++i){
            int u,v;
            cin>>u>>v;
        }
        vector<bool> ans;
        vector<vector<int>> queries(k);
        for(int i=0;i<k;++i){
            string type;
            cin>>type;
            int u,v;
            cin>>u>>v;
            u--,v--;
            if(type=="cut"){
                queries[i] = {0,u,v};
            }else{
                queries[i] = {1,u,v};
            }
        }
        for(int i=k-1;i>=0;--i){
            if(queries[i][0]==0){
                dsu.unite(queries[i][1],queries[i][2]);
            }else{
                if(dsu.find(queries[i][1])==dsu.find(queries[i][2])){
                    ans.push_back(true);
                }else{
                    ans.push_back(false);
                }
            }
        }
        
        for(int i=ans.size()-1;i>=0;--i){
            cout << (ans[i]?"YES":"NO") << endl;
        }
    }
    return 0;
}