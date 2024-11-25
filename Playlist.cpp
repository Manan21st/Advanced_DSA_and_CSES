#include <iostream>
#include <bits/stdc++.h>
// #define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(vector<int>& arr){
    int n = arr.size();
    int ans=0;
    map<int,int> mp;
    int l=0;
    for(int r=0;r<n;++r){
        if(mp.find(arr[r])==mp.end()){
            mp.insert({arr[r],r});
        }else{
            if(mp[arr[r]]>=l){
                l = mp[arr[r]]+1;
            }
            mp[arr[r]] = r;
        }
        ans = max(ans,r-l+1);
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
        for(int i =0;i<n;++i){
            cin >> arr[i];
        }
        cout << solve(arr) << endl;
    }
    return 0;
}