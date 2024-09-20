#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

pair<int,int> solve(vector<int>& arr, int x){
    int n = arr.size();
    map<int,int> mp;
    for(int i=0;i<n;++i){
        if(mp.find(x-arr[i]) != mp.end()){
            return {mp[x-arr[i]]+1,i+1};
        }
        mp[arr[i]] = i;
    }
    return {-1,-1};
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test=1;
    // cin>>test;
    for(int t =0;t<test;++t){
        int n,x;
        cin>>n>>x;
        vector<int> arr(n);
        for(int i=0;i<n;++i){
            cin>>arr[i];
        }
        auto ans = solve(arr,x);
        if(ans.first == -1){
            cout <<"IMPOSSIBLE"<< endl;
        }else{
            cout << ans.first << " " << ans.second << endl;
        }
    }
    return 0;
}
