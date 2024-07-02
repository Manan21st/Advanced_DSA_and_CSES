#include <iostream>
#include <bits/stdc++.h>

using namespace std;

//for checking product of digits of a number

int dp[18][64][64][64][64][2][2];
map<int,vector<int>> mp;

int solve(int pos,int p_2,int p_3,int p_5,int p_7,int isZero,int hasStarted,int length,int reqProd){
    if(pos==length){
        int curr =(2,p_2)*(3,p_3)*(5,p_5)*(7,p_7) ;
        if(isZero){
            curr = 0;
        }
        return curr == reqProd;
    }

    int &ans = dp[pos][p_2][p_3][p_5][p_7][isZero][hasStarted];
    if(ans!=-1){
        return ans;
    }

    for(int i=0;i<=9;i++){
        if(i==0){
            if(!hasStarted){
                ans+=solve(pos+1,p_2,p_3,p_5,p_7,1,0,length,reqProd);
            }else{
                ans+=solve(pos+1,p_2,p_3,p_5,p_7,1,1,length,reqProd);
            }
        }
        else{
            ans+=solve(pos+1,p_2+mp[i][0],p_3+mp[i][1],p_5+mp[i][2],p_7+mp[i][3],isZero,1,length,reqProd);
        }
    }
    return ans;
}

int main(){
    mp[1] = {0,0,0,0};
    mp[2] = {1,0,0,0};
    mp[3] = {0,1,0,0};
    mp[4] = {2,0,0,0};
    mp[5] = {0,0,1,0};
    mp[6] = {1,1,0,0};
    mp[7] = {0,0,0,1};
    mp[8] = {3,0,0,0};
    mp[9] = {0,2,0,0};
    memset(dp,-1,sizeof(dp));
    return 0;
}