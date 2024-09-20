#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

int solve(vector<int>& pieces,int n){
    sort(pieces.begin(),pieces.end());
    int ans =0;
    for(int i =0;i<pieces.size()-1;i++){
        if(pieces[i]!=1){
            ans += pieces[i]-1;
        }
    }
    ans+=(n-pieces[pieces.size()-1]);
    return ans;
}

signed main(){
    int test;
    cin >> test;
    for(int i =0;i<test;i++){
        int n,k;
        cin >> n >> k;
        vector<int> temp(k);
        for(int j=0;j<k;j++){
            cin >> temp[j];
        }
        cout << solve(temp,n) << endl;
    }
    return 0;
}
