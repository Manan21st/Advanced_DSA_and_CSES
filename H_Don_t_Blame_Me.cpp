#include <iostream>
#include <bits/stdc++.h>
// #define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(int idx, int mask, int k, vector<int>& arr, vector<vector<int>>& dp){
    if(arr.size()<=idx){
        return __builtin_popcount(mask)==k ? 1 : 0;
    }
    if(dp[idx][mask]!=-1){
        return dp[idx][mask];
    }
    int ans1 = solve(idx+1, mask, k, arr, dp);
    int ans2 = solve(idx+1, (mask&(arr[idx])), k, arr, dp);
    return dp[idx][mask] = (ans1%mod + ans2%mod)%mod;
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int n, k;
        cin >> n >> k;
        vector<int> arr(n);
        vector<vector<int>> dp(n+1,vector<int> ((1<<7),-1));
        for(int i=0;i<n;++i){
            cin >> arr[i];
        }
        cout << solve(0,(1<<7)-1,k,arr,dp) << endl;
    }
    return 0;
}