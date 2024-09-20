#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(vector<int>& arr){
    int n = arr.size();
    int ans = 0;
    for(int i=1;i<n;++i){
        if(arr[i]<arr[i-1]){
            ans+=abs(arr[i-1]-arr[i]);
            arr[i]+=abs(arr[i-1]-arr[i]);
        }
    }
    return ans;
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test=1;
    // cin>>test;
    for(int t =0;t<test;++t){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0;i<n;++i){
            cin >> arr[i];
        }
        cout << solve(arr) << endl;
    }
    return 0;
}