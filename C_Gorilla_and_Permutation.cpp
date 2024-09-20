#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

void solve(int n, int m, int k){
    vector<int> ans;
    for(int i =n;i>m;i--){
        ans.push_back(i);
    }

    for(int i =1;i<m+1;i++){
        ans.push_back(i);
    }

    for(int i =0;i<ans.size();i++){
        cout << ans[i] << " ";
    }
}

signed main(){
    int test;
    cin >> test;
    for(int i =0;i<test;i++){
        int n,m,k;
        cin >> n >> m >> k;
        solve(n,m,k);
        cout << endl;
    }
    return 0;
}
