#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

int dp[1001][1001];

ll solve(vector<vector<char>>& grid,int i,int j){
    if(i>=grid.size() || j>=grid[0].size() || grid[i][j]=='*'){
        return 0;
    }
    if(i==grid.size()-1 && j==grid[0].size()-1){
        return 1;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    ll ans1=solve(grid,i+1,j)%mod;
    ll ans2=solve(grid,i,j+1)%mod;
    return dp[i][j]=(ans1%mod+ans2%mod)%mod;
}

int main(){
    int n;
    cin >> n;
    vector<vector<char>> grid(n,vector<char>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin >> grid[i][j];
        }
    }
    memset(dp,-1,sizeof dp);
    cout<< solve(grid,0,0) << endl;
    return 0;
}
