#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(vector<pair<int,int>>& arr){
    int n = arr.size();
    sort(arr.begin(),arr.end(),[&](pair<int,int> a, pair<int,int> b){
        return a.first<b.first or (a.first==b.first and a.second>b.second);
    });

    vector<int> dp;
    for(auto& x: arr){
        int right = x.second;
        auto pos = lower_bound(dp.begin(),dp.end(),right)-dp.begin();
        if(pos!=dp.size()){
            dp[pos] = right;
        }else{
            dp.push_back(right);
        }
    }
    return dp.size();
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int n;
        cin >> n;
        vector<pair<int,int>> arr(n);
        for(int i=0;i<n;++i){
            cin >> arr[i].first >> arr[i].second;
        }
        cout << solve(arr) << endl;
    }
    return 0;
}