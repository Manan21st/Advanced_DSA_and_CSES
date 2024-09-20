#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

int solve(vector<int>& arr){
    int max_Val = 1000001;
    for(int gcd = max_Val; gcd>=1;gcd--){
        int div =0;
        for(int i = gcd ;i<=max_Val;i+=gcd){
            div+=arr[i];
        }
        if(div>=2){
            return gcd;
        }
    }
    return 1;
}

signed main(){
    int n;
    cin >> n;
    
    vector<int> arr(1000001,0);
    for(int i  =0 ;i<n;i++){
        int x;
        cin >> x;
        arr[x]++;
    }
    cout << solve(arr) << endl;
    return 0;
}
