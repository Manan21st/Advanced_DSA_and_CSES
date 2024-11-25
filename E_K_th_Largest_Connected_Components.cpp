#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

class DSU{
public:
    vector<int> parent;
    vector<int> size;
    vector<vector<int>> largest;
    DSU(int n){
        parent.resize(n);
        size.resize(n,1);
        largest.resize(n);
        for(int i=0;i<n;++i){
            parent[i] = i;
            largest[i].push_back(i+1);
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
        largest[a].insert(largest[a].end(),largest[b].begin(),largest[b].end());
        largest[b].clear();
        sort(largest[a].begin(),largest[a].end(),greater<int>());
        if(largest[a].size()>10){
            largest[a].resize(10);
        }
    }
    vector<int> query(int v){
        int a = find(v);
        return largest[a];
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
            int type;
            cin >> type;
            if(type==1){
                int u,v;
                cin >> u >> v;
                u--,v--;
                dsu.unite(u,v);
            }
            else{
                int v,k;
                cin >> v >> k;
                v--;
                vector<int> ans = dsu.query(v);
                if(ans.size()<k){
                    cout << -1 << endl;
                }
                else{
                    cout << ans[k-1] << endl;
                }
            }
        }        
    }
    return 0;
}