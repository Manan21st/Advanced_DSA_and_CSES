#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(vector<int>& arr, vector<int>& barr){
    int n = arr.size();
    int ans = *max_element(arr.begin(),arr.end())+(*max_element(barr.begin(),barr.end()));

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
        vector<int> barr(n);
        for(int i=0;i<n;++i){
            cin >> barr[i];
        }
        cout << solve(arr,barr) << endl;
    }
    return 0;
}