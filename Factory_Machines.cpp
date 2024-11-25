#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

bool check(int mid, int t, vector<int>& arr){
    int n = arr.size();
    int sum =0;
    for(int i=0;i<n;++i){
        sum+=(mid/arr[i]);
        if(sum>=t){
            return true;
        }
    }
    return false;
}

int solve(vector<int>& arr, int t){
    int ans =0;
    int min_time = *min_element(arr.begin(),arr.end());
    sort(arr.begin(),arr.end());
    int l = 1;
    int r = t*min_time;
    while(l<=r){
        int mid = (l+r)/2;
        if(check(mid,t,arr)){
            ans=mid;
            r = mid-1;
        }else{
            l = mid+1;
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
        int n,k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i=0;i<n;++i){
            cin >> arr[i];
        }
        cout << solve(arr, k) << endl;
    }
    return 0;
}