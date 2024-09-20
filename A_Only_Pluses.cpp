#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

int solve(vector<int>& array){
    int ans =0;
    sort(array.begin(),array.end());
    for(int i =0;i<5;i++){
        array[0]++;
        sort(array.begin(),array.end());
    }
    ans = array[0]*array[1]*array[2];
    return ans;
}

signed main(){
    int test; 
    cin >> test;
    for(int i = 0;i<test;i++){
        vector<int> temp(3);
        cin >> temp[0] >> temp[1] >> temp[2];
        cout << solve(temp) << endl;
    }
    return 0;
}
