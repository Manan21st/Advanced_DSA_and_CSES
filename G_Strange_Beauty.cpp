#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int dp[1000001], cnt[1000001];

int solve(vector<int>& nums){
    int n = nums.size();
    int ans = 0;
    for(int i=1;i<=200100;i++){
        dp[i] += cnt[i];
        for(int j = i;j<=200100;j+=i){
            dp[j] = max(dp[j],dp[i]);
        }
        ans = max(ans,dp[i]);
    }
    return n-ans;
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t;i++){
        memset(dp,0,sizeof(dp));
        memset(cnt,0,sizeof(cnt));
        int n;
        cin >> n;
        vector<int> nums(n);
        for(int j = 0;j<n;j++){
            cin >> nums[j];
            cnt[nums[j]]++;
        }
        cout << solve(nums) << endl;
    }
    return 0;
}