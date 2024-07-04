#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;



// int solve(vector<int>& weight,vector<int>& value,int n,int w,int idx){
//     if(idx == n || w<=0){
//         return 0;
//     }
//     if(dp[idx][w]!=-1){
//         return dp[idx][w];
//     }
//     int ans =0;
//     if(weight[idx]<=w){
//         ans = max(ans,value[idx]+solve(weight,value,n,w-weight[idx],idx+1));
//     }
//     ans = max(ans,solve(weight,value,n,w,idx+1));
//     return dp[idx][w] = ans;
// }

int dp[110][100010];

int possible(vector<int>& weight, vector<int>& value,int idx,int profit){
    if(idx==weight.size()){
        return profit==0 ? 0 : 1e14;
    }
    if(dp[idx][profit]!=-1){
        return dp[idx][profit];
    }
    int ans1 = possible(weight,value,idx+1,profit);
    int ans2 = 1e14;
    if(value[idx]<=profit){
        ans2 = weight[idx]+possible(weight,value,idx+1,profit-value[idx]);
    }
    return dp[idx][profit] = min(ans1,ans2);
}

int solve(vector<int>& weight,vector<int>& value,int w){
    memset(dp,-1,sizeof(dp));
    int ans = 0;
    for(int profit = 0;profit<=1e5;++profit){
        if(possible(weight,value,0,profit)<=w){
            ans = max(ans,profit);
        }
    }
    return ans;
}

signed main(){
    int n,w;
    cin>>n>>w;
    vector<int> weight(n),value(n);
    for(int i =0;i<n;i++){
        cin >> weight[i] >> value[i];
    }
    cout << solve(weight,value,w) << endl;
    return 0;
}
