#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll dp[1000001];

ll solve(vector<int>& coins, int target,int sum){
    if(target==sum){
        return 0;
    }
    if(sum>target){
        return INT_MAX;
    }
    if(dp[sum]!=-1){
        return dp[sum];
    }
    ll ans=INT_MAX;
    for(int i=0;i<coins.size();i++){
        ll temp =solve(coins,target,sum+coins[i]);
        if(temp!=INT_MAX){
            ans=min(ans,temp+1);
        }
    }
    return dp[sum]=ans;
}

int main(){
    int n,x;
    cin>>n>>x;
    vector<int> coins(n);
    
    for(int i=0;i<n;i++){
        cin>>coins[i];
    }

    memset(dp,-1,sizeof(dp));

    ll ans = solve(coins,x,0);

    if(ans!=INT_MAX){
        cout << ans << endl;
    }else{
        cout << -1 << endl;
    }


    return 0;
}