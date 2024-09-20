#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

int solve(){
    return 0;
}

signed main(){
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int n,k;
        cin >> n >> k;
        vector<string> arr(n);
        for(int i=0;i<n;++i){
            cin>>arr[i];
        }
        vector<vector<int>> ans(n/k+n%k, vector<int> (n/k+n%k));
        for(int i=0;i<n;i+=k){
            for(int j=0;j<n;j+=k){
                ans[i/k][j/k] = arr[i][j]-'0';
            }
        }
        for(int i=0;i<ans.size();++i){
            for(int j=0;j<ans[0].size();++j){
                cout<<ans[i][j];
            }
            cout<<endl;
        }

    }
    return 0;
}
