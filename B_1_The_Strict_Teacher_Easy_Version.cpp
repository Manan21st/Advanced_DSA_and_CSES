#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(int n, vector<int>& arr, vector<int>& queries){
    int ans=0;
    if(arr[0]>arr[1]){
        swap(arr[0],arr[1]);
    }
    if(queries[0]<arr[1] and queries[0]>arr[0]){
        int mid = (arr[0]+arr[1])/2;
        ans=min(abs(mid-arr[0]),abs(mid-arr[1]));
    }else if(queries[0]<arr[0]){
        ans=abs(queries[0]-arr[0]);
        ans+=abs(1-queries[0]);
    }else{
        ans=abs(queries[0]-arr[1]);
        ans+=abs(n-queries[0]);
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
        int n,m,q;
        cin >> n >> m >> q;
        vector<int> arr(m);
        for(int i=0;i<m;++i){
            cin >> arr[i];
        }
        vector<int> queries(q);
        for(int i=0;i<q;++i){
            cin >> queries[i];
        }
        cout<<solve(n,arr,queries)<<endl;
    }
    return 0;
}