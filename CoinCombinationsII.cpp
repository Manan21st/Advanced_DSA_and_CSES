#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

ll dp[1000001];

ll solve(vector<int>& coins, int target,int sum,int index){
    if(target==sum){
        return 1;
    }
    if(sum>target || index>=(int)(coins.size())){
        return 0;
    }
    if(dp[sum]!=-1){
        return dp[sum];
    }
    
    ll ans1=solve(coins,target,sum+coins[index],index)%mod;
    ll ans2=solve(coins,target,sum,index+1)%mod;
    return dp[sum]=((ans1%mod)+(ans2%mod))%mod;
}

int main(){
    memset(dp,-1,sizeof(dp));
    int n,x;
    cin>>n>>x;

    vector<int> coins(n);

    for(int i =0;i<n;i++){
        cin>>coins[i];
    }
    cout<< solve(coins,x,0,0)%mod << endl;
    return 0;
}
