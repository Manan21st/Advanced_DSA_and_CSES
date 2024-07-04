#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define mod 1000000007

using namespace std;

// recursive solution n*k*K

// ll solve(vector<int>& allowed,ll candies, ll idx){
//     if(idx==n || candies<0){
//         return 0;
//     }
//     if(candies==0){
//         return 1;
//     }
//     ll ans=0;
//     for(int i =0;i<=min(allowed[idx],candies);i++){
//         ans = (ans+solve(allowed,candies-i,idx+1))%mod;
//     }
//     return ans%mod;
// }


// dp+iterative+prefix solution n*k

int dp[2][100011];
int prefix[100011];

ll solve(vector<int>& allowed,int candies){

    for(int row=allowed.size();row>=0;--row){
        for(int k =0;k<=candies;++k){
            int &ans = dp[row%2][k];
            if(row==allowed.size()){
                ans = (k==0);
                continue;
            }
            int max_candies = min(allowed[row],k);
            int start = k-max_candies;
            int end = k;
            ans = prefix[end]-prefix[start]+dp[(row+1)%2][start];
            ans = (ans+mod)%mod;
        }
        prefix[0] = dp[row%2][0];
        for(int k =1;k<=candies;++k){
            prefix[k] = (prefix[k-1]+dp[row%2][k])%mod;
        }
    }
    return dp[0][candies];
}


signed main(){
    int n,k;
    cin>>n>>k;
    vector<int> allowed(n);
    for(int i = 0; i < n; i++){
        cin>>allowed[i];
    }
    memset(dp,-1,sizeof dp);
    memset(prefix,0,sizeof prefix);
    cout<< solve(allowed,k) <<endl;
    return 0;
}
