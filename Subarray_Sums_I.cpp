#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int n;

int solve(vector<int>& arr, int x){
    int ans=0;
    int sum=0;
    int l=0;
    int r=0;
    while(r<n){
        while(r<n and sum<x){
            sum+=arr[r];
            ++r;
        }
        while(l<=r and sum>x){
            sum-=arr[l];
            ++l;
        }
        if(sum==x){
            ans++;
            sum-=arr[l];
            l++;
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
        int x;
        cin >> n >> x;
        vector<int> arr(n);
        for(int i =0;i<n;++i){
            cin >> arr[i];
        }
        cout << solve(arr,x) << endl;
    }
    return 0;
}