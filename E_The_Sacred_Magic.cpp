#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

vector<int> solve(vector<int>& arr, vector<vector<int>>& queries){
    int n = arr.size();
    int q = queries.size();
    
    for(int i =0;i<q;i++){
        int l = queries[i][0];
        int r = queries[i][1];
    }
    return ans;
}

signed main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i =0;i<n;i++){
        cin >> arr[i];
    }
    int q;
    cin >> q;
    vector<vector<int>> queries(q,vector<int> (2));
    for(int i=0;i<q;i++){
        cin >> queries[i][0] >> queries[i][1];
    }
    vector<int> toprint;
    toprint = solve(arr,queries);
    for(int i =0;i<toprint.size();i++){
        cout << toprint[i] << endl;
    }
    return 0;
}
