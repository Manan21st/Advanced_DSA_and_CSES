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

ll solve(vector<int>& coins, int target){
    int n = coins.size();
    dp[0]=1;
    for(int i =1;i<=n;++i){
        for(int j =0;j<=target;++j){
            if(j-coins[i-1]>=0){
                dp[j] = (dp[j]%mod + dp[j-coins[i-1]]%mod)%mod;
            }
        }
    }
    return dp[target];    
}

int main(){
    int n,x;
    cin>>n>>x;

    vector<int> coins(n);

    for(int i =0;i<n;i++){
        cin>>coins[i];
    }
    cout<< solve(coins,x)%mod << endl;
    return 0;
}
