#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(int n, vector<int>& arr, int q){
    int ans=0;
    int idx = lower_bound(arr.begin(),arr.end(),q)-arr.begin();
    if(idx==arr.size()){
        ans=abs(arr[arr.size()-1]-q);
        ans+=abs(n-q);
    }else if(idx==0){
        ans=abs(arr[0]-q);
        ans+=abs(1-q);
    }else{
        int mid = (arr[idx]+arr[idx-1])/2;
        ans = min(abs(mid-arr[idx-1]),abs(mid-arr[idx]));
    }
    return ans;
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int n,m,q;
        cin >> n >> m >> q;
        vector<int> arr(m);
        for(int i=0;i<m;++i){
            cin >> arr[i];
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<q;++i){
            int query;
            cin >> query;
            cout<<solve(n,arr,query)<<endl;
        }
    }
    return 0;
}