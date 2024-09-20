#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

void solve(int pos, int k, int sum, vector<int> &arr, vector<int> &subs, set<vector<int>>& ans){
    if(pos == arr.size()){
        if(sum % k == 0){
            ans.insert(subs);
        }
        return;
    }
    for(int j = 1; j <= arr[pos]; j++){
        subs.push_back(j);
        solve(pos + 1, k, sum + j, arr, subs, ans);
        subs.pop_back();
    }
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test=1;
    // cin>>test;
    for(int t =0;t<test;++t){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i =0;i<n;++i){
            cin>>arr[i];
        }
        vector<int> subs;
        set<vector<int>> ans;
        
        solve(0, k, 0, arr, subs, ans);
        for (auto s : ans){
            for (int val : s){
                cout << val << " ";
            }
            cout << endl;
        }
    }
    return 0;
}

