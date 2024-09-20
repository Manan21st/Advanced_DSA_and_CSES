#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

vector<int> solve(vector<int>& arr){
    int n = arr.size();
    vector<int> ans(n);
    ans[0] = arr[n-1];
    for(int i=1;i<n;++i){
        ans[i] = arr[i-1];
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0;i<n;++i){
            cin>>arr[i];
        }
        vector<int> ans = solve(arr);
        for(auto temp:ans){
            cout<<temp<<" ";
        }
        cout<<endl;
    }
    return 0;
}
