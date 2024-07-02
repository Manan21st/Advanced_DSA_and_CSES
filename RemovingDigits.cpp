#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007

using namespace std;

// ll dp[1000001];

// ll solve(int n){
//     if(n==0){
//         return 0;
//     }
//     if(n<0){
//         return INT_MAX;
//     }
//     if(dp[n]!=-1){
//         return dp[n];
//     }
//     ll ans=INT_MAX;
//     for(char c:to_string(n)){
//         if(c!='0'){
//             ans=min(ans,solve(n-(c-'0'))+1);
//         }
//     }
//     return dp[n]=ans;
// }

ll solveIterative(int n){
    vector<int> dp(n+1,INT_MAX);
    dp[0]=0;
    for(int i =1;i<=n;i++){
        for(char c:to_string(i)){
            if(c!='0'){
                dp[i]=min(dp[i],dp[i-(c-'0')]+1);
            }
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    //memset(dp,-1,sizeof(dp));
    cout<< solveIterative(n) << endl;
    return 0;
}
