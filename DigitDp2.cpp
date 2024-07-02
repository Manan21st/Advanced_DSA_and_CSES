#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//for checking sum of digits of a number and gcd of digits of a number

int dp[18][18*9+1][10];

int solve(int pos,int sum,int g,int length,int reqSum,int reqGcd){
    if(pos==length){
        return sum == reqSum && g == reqGcd;
    }
    if(dp[pos][sum][g]!=-1){
        return dp[pos][sum][g];
    }

    int ans = 0;
    for(int i =0;i<=9;i++){
        ans+=solve(pos+1,sum+i,gcd(g,i),length,reqSum,reqGcd);
    }
    return dp[pos][sum][g] = ans;
}

int main(){
    memset(dp,-1,sizeof(dp));
    cout<< solve(0,0,0,4,10,1) << endl;
    return 0;
}