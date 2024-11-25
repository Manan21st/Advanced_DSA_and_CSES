#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define endl '\n'

using namespace std;

ll solve(vector<int>& arr){
    int n = arr.size();
    ll ans = 0;
    unordered_map<int,ll> freq;

    for(int i=0;i<n;++i){
        for(int j =i+1;j<n;++j){
            int val = arr[i] ^ arr[j];
            freq[val]++;
        }
    }

    for(auto x : freq){    
        int val = x.second;
        if(val>1){
            ans += (val*(val-1))/2;
        }
    }
    return ans*8;
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;++i){
            cin>>arr[i];
        }
        cout<<solve(arr)<<endl;
    }
    return 0;
}