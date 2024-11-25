#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(vector<int>& arr, int n, int k){
    int ans=0;
    int gold=0;
    for(int i=0;i<n;++i){
        if(arr[i]>=k){
            gold+=arr[i];
        }else if(arr[i]==0 and gold>0){
            gold--;
            ans++;
        }
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
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        for(int i=0;i<n;++i){
            cin>>arr[i];
        }
        cout<<solve(arr,n,k)<<endl;
    }
    return 0;
}