#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 998244353

using namespace std;

int dp[85][85];

int recur(vector<int>& arr, int k, int idx){
    if(k==0){
        return 1;
    }
    if(idx>=arr.size() || k<0){
        return 0;
    }
    if(dp[k][idx]!=-1){
        return dp[k][idx];
    }
    int ans=0;
    for(int i =idx+1;i<arr.size();i++){
        if(arr[i]>arr[idx]){
            ans=(ans%mod + recur(arr,k-1,i)%mod)%mod;
            ans%=mod;
        }
    }
    return dp[k][idx] = ans;
}

void solve(vector<int>& arr){
    vector<int> ans(arr.size()+1,0);
    ans[1] = arr.size();
    for(int i =2;i<=arr.size();i++){
        for(int j =0;j<arr.size();j++){
            memset(dp,-1,sizeof(dp));
            ans[i]=(ans[i]%mod + recur(arr,i,j)%mod)%mod;
            ans[i]%=mod;
        }
    }
    for(int i =1;i<=arr.size();i++){
        cout << ans[i] << " ";
    }
}

signed main(){
    int n;
    cin >> n;
    vector<int> array(n);
    for(int i =0;i<n;i++){
        cin >> array[i];
    }
    solve(array);
    return 0;
}
