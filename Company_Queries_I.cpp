#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

class TreeAncestor {
    vector<vector<int>> dp;
public:
    TreeAncestor(int n, vector<int>& parent) {
        dp = vector<vector<int>> (32,vector<int> (n));
        dp[0]=parent;
        for(int i=1;i<32;++i){
            for(int j =0;j<n;++j){
                int halfway = dp[i-1][j];
                if(halfway==-1){
                    dp[i][j]=-1;
                }else{
                    dp[i][j] = dp[i-1][halfway];
                }
            }
        }
    }

    int query(int node,int k){
        for(int i=30;i>=0;--i){
            if(k&(1<<i)){
                node = dp[i][node];
                if(node==-1){
                    return -1;
                }
            }
        }
        return node;
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
        vector<int> parent(n);
        parent[0] = -1;
        for(int i=1;i<n;++i){
            cin>>parent[i];
            parent[i]--;
        }
        TreeAncestor ta(n, parent);
        for(int i=0;i<q;++i){
            int node, k;
            cin>>node>>k;
            int ans = ta.query(node-1, k);
            if(ans==-1){
                cout << -1 << endl;
            }else{
                cout << ans+1 << endl;
            }
        }
    }
    return 0;
}