#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

int solve(vector<int>& arr){
    int n = arr.size();
    int mx = *max_element(arr.begin(),arr.end());
    vector<int> cnt(mx+1,0);
    for(int i =0;i<n;i++){
        cnt[arr[i]]++;
    }
    vector<int> pairs(mx+1,0);
    for(int i =1;i<=mx;i++){
        for(int j =i;j<=mx;j+=i){
            pairs[i] += cnt[j];
        }
        pairs[i] = (pairs[i]*(pairs[i]-1))/2;
    }
    for(int i =mx;i>=1;i--){
        for(int j =2*i;j<=mx;j+=i){
            pairs[i] -= pairs[j];
        }
    }
    return pairs[1];
}

signed main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i =0;i<n;i++){
        cin >> arr[i];
    }
    cout << solve(arr) << endl;
    return 0;
}
