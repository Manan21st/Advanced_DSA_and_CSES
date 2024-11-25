#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(vector<int>& arr){
    int ans=0;
    int n = arr.size();
    
    if(arr[0] == arr[n - 1]){
       return (n - 1) * 2 + 1;
    }else{
        if(arr[0] != 0){
            return (n - 1) * 2 + 1;
        }else{
            return (n - 2) * 2 + 2;
        }
    }
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i =0;i<n;++i){
            cin >> arr[i];
        }
        cout << solve(arr) << endl;
    }
    return 0;
}