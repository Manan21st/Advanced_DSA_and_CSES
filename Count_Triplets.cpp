#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(vector<int>& arr){
    int n= arr.size();
    int ans=0;
    for(int j=0;j<=99;++j){
        int i=0;
        int k=j;
        while(k<arr.size()){
            int temp = (abs(arr[i]-arr[k]) + i + k)/2;
            int temp2 = (i+k - abs(arr[i]-arr[k])) /2;
            if(temp2<min(i,k)){
                ans++;
                // cout << i+1 << " " << k+1 << " " << temp << endl; 
            }

            if(temp>=max(i,k)){
                ans++;
            }

            if(abs(arr[i]-arr[k])==abs(i-k) and abs(i-k)>1){
                ans++;
                // cout << i+1 << " " << k+1 << endl;
            }
            
            k++;
            i++;
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
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0;i<n;++i){
            cin >> arr[i];
        }
        cout << solve(arr) << endl;
    }
    return 0;
}

