#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

int solve(vector<int>& nums, int k){
    if(k==nums.size()-1){
        return 0;
    }
    sort(nums.begin(),nums.end());  
    int diff =INT_MAX;
    for(int i =0;i<=k;i++){
        int temp = nums[nums.size()-k-1+i]-nums[i];
        diff = min(diff,temp);
    }
    return diff;
}

signed main(){
    int n,k;
    cin>>n>>k;
    vector<int> nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout << solve(nums,k) << endl;
    return 0;
}
