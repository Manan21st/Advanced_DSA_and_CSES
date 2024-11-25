#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(vector<pair<int, int>>& arr){
    int n = arr.size();
    int maxi = 0;
    int ans = 0;

    for(int i = 0; i < n; i++){
        maxi += arr[i].second;
        arr[i].first = arr[i].first - arr[i].second; 
    }
    
    sort(arr.begin(), arr.end());
    ans = maxi;
    int sum = maxi + arr[0].first;  

    for(int i = 1; i < n; i++){
        sum += arr[i].first; 
        ans = min(ans, sum);
    }
    
    return ans;
}

signed main() {
    // This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    for(int t = 0; t < test; ++t){
        int n;
        cin >> n;
        
        vector<pair<int, int>> arr(n);
        for(int i = 0; i < n; i++){
            cin >> arr[i].first;
        }
        for(int i = 0; i < n; i++){
            cin >> arr[i].second; 
        }
        
        cout << solve(arr) << endl;
    }
    return 0;
}
