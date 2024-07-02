#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;
ll dp[5001][5001];
ll solve(vector<int>& list, int n, int i, int j){
    if(i>j){
        return 0;
    }
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    ll ans1 = list[i] + min(solve(list,n,i+1,j-1),solve(list,n,i+2,j));
    ll ans2 =list[j] + min(solve(list,n,i+1,j-1),solve(list,n,i,j-2));
    return dp[i][j]=max(ans1,ans2);
}

int main(){
    int n;
    cin >> n;
    vector<int> list(n);
    for(int i =0;i<n;i++){
        cin >> list[i];
    }
    memset(dp,-1,sizeof dp);
    cout << solve(list,n,0,n-1) << endl;
    return 0;
}
