#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

int dp[101][100001];

int solve(vector<int>& coins,int sum,int index){
    if(sum==0){
        return true;
    }
    if(sum<0 || index>=coins.size()){
        return false;
    }
    if(dp[index][sum]!=-1){
        return dp[index][sum];
    }
    int ans1 = solve(coins,sum-coins[index],index+1);
    int ans2 = solve(coins,sum,index+1);
    return dp[index][sum] = ans1 || ans2;
}

int main(){
    int n;
    cin >> n;
    vector<int> coins(n);
    for(int i =0;i<n;i++){
        cin>>coins[i];
    }

    memset(dp,-1,sizeof dp);

    int sum = 0;
    for(int i : coins){
        sum+=i;
    }

    vector<int> ans;
    for(int i =1;i<=sum;i++){
        if(solve(coins,i,0)){
            ans.push_back(i);
        }
    }
    
    cout << ans.size() << endl;
    for(int i=0;i<(int)ans.size();i++){
        cout << ans[i] << " ";
    }
    return 0;
}
