#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

vector<int> solve(vector<pair<int,int>>& arr){
    int sum =0;
    vector<int> ans(arr.size());
    for(int i =0;i<arr.size();i++){
        sum+=arr[i].first;
        ans[i] = arr[i].first;
    }
    if(sum==0){
        return ans;
    }
    for(int i=0;i<arr.size();i++){
        if(sum==0){
            return ans;
        }
        int diff = min(arr[i].second-arr[i].first,-sum);
        sum+=diff;
        ans[i]+=diff;
    }
    return ans;
}

signed main(){
    int n;
    cin >> n;
    vector<pair<int,int>> array(n);
    for(int i =0;i<n;i++){
        cin >> array[i].first >> array[i].second;
    }
    int left=0;
    int right=0;
    for(int i =0;i<n;i++){
        left+=array[i].first;
        right+=array[i].second;
    }
    if(left>0 || right<0){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
        vector<int> ans = solve(array);
        for(int i =0;i<n;i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
