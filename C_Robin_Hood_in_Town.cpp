#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(vector<int>& arr, int n){
    if(n<=2){
        return -1;
    }
    int total = 0;
    for(int i=0;i<n;++i){
        total+=arr[i];
    }
    
    vector<int> x(n);
    for(int i=0;i<n;++i){
        x[i] = max(0LL,2*n*arr[i]-total+1);
    }
    sort(x.begin(),x.end());
    
    int count=0;
    for(int i=0;i<n;++i){
        count++;
        if(count>n/2){
            return x[i];
        }
    }
    return -1;
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
        cout << solve(arr, n) << endl;
    }
    return 0;
}