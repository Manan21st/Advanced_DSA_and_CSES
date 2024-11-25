#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(vector<int>& arr, int x){
    int n = arr.size();
    double total = accumulate(arr.begin(),arr.end(),0ll);
    int maxi = *max_element(arr.begin(),arr.end());
    int ans=max((int)ceil(total/x),maxi);
    return ans;
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int n,x;
        cin >> n >> x;
        vector<int> arr(n);
        for(int i=0;i<n;++i){
            cin >> arr[i];
        }
        cout<<solve(arr,x)<<endl;
    }
    return 0;
}

