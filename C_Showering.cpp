#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(vector<pair<int,int>>& inter, int s,int m){
    if(inter[0].first > m){
        return 0;
    }
    if(inter[0].first >= s){
        return 1;
    }
    for(int i=1;i<inter.size();++i){
        if(inter[i].first - inter[i-1].second >= s){
            return 1;
        }
    }
    if(m - inter[inter.size()-1].second >= s){
        return 1;
    }
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int n,s,m;
        cin>>n>>s>>m;
        vector<pair<int,int>> inter(n);
        for(int i=0;i<n;++i){
            int l,r;
            cin >> l >> r;
            inter[i] = {l,r};
        }
        sort(inter.begin(),inter.end());
        if(solve(inter,s,m)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
