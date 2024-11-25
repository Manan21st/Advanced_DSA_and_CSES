#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

void solve(int m){
    vector<int> ans;
    for(int i=10;i>=0;--i){
        int three = pow(3,i);
        while(m>=three){
            ans.push_back(i);
            m-=three;
        }
    }
    sort(ans.begin(),ans.end());
    cout << ans.size() << endl;
    for(int i=0;i<ans.size();++i){
        cout << ans[i] << " ";
    }
    cout << endl;
    return;
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test=1;
    // cin>>test;
    for(int t =0;t<test;++t){
        int m;
        cin >> m;
        solve(m);
    }
    return 0;
}