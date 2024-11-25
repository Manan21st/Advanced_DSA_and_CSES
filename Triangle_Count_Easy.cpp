#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(vector<int>& arr){
    int n = arr.size();
    if(n==1){
        return 0;
    }
    int ans =0;
    vector<pair<int,int>> pairs;
    for(int i=1;i<n;++i){
        int mini = arr[i] - arr[i-1] + 1;
        int maxi = arr[i] + arr[i-1] - 1;
        pairs.push_back({mini,maxi});
    }
    
    sort(pairs.begin(),pairs.end());
    int baharMin = pairs[0].first;
    int baharMax = pairs[0].second;
    
    vector<pair<int,int>> merged;
    for(int i=1;i<n-1;++i){
        int mini = pairs[i].first;
        int maxi = pairs[i].second;
        if(mini>baharMax){
            merged.push_back({baharMin,baharMax});
            baharMin = mini;
            baharMax = maxi;
        }else{
            baharMax = max(baharMax, maxi);
        }
    }
    
    merged.push_back({baharMin,baharMax});
    
    for(int i=0;i<merged.size();++i){
        ans += (merged[i].second - merged[i].first + 1);
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
        sort(arr.begin(),arr.end());
        cout << solve(arr) << endl;
    }
    return 0;
}