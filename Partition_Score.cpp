#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(vector<int>& arr, int k){
    int n= arr.size();
    int ans=0;
    sort(arr.begin(),arr.end());
    ans+=arr[n-1]+arr[n-2]+arr[0];
    if(k==1){
        ans+=arr[n-1];
    }else{
        ans+=arr[n-k-1];
    }
    return ans;
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int n,k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i=0;i<n;++i){
            cin >> arr[i];
        }
        cout << solve(arr,k) << endl;
    }
    return 0;
}