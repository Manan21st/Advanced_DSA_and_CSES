#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(vector<int>& app, vector<int>& apart, int k){
    int ans = 0;
    sort(app.begin(), app.end());
    sort(apart.begin(), apart.end());
    int i = 0, j = 0;
    while(i < app.size() and j < apart.size()){
        if(abs(app[i]-apart[j])<=k){
            ans++;
            i++;
            j++;
        }
        else if(app[i]<apart[j]){
            i++;
        }else if(app[i]>apart[j]){
            j++;
        }else{
            break;
        }
    }
    return ans;
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test=1;
    // cin>>test;
    for(int t =0;t<test;++t){
        int n,m,k;
        cin >> n >> m >> k;
        vector<int> a(n);
        vector<int> b(m);
        for(int i =0;i<n;++i){
            cin >> a[i];
        }
        for(int i=0;i<m;++i){
            cin >> b[i];
        }
        cout << solve(a,b,k) << endl;
    }
    return 0;
}
