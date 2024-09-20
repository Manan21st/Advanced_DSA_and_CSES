#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(int idx, int sum1, int sum2, vector<int> &arr){
    if(idx==arr.size()){
        return abs(sum1-sum2);
    }
    int ans1 = solve(idx+1, sum1+arr[idx], sum2, arr);
    int ans2 = solve(idx+1, sum1, sum2+arr[idx], arr);
    return min(ans1, ans2);
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test=1;
    // cin>>test;
    for(int t =0;t<test;++t){
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i=0;i<n;++i){
            cin >> arr[i];
        }
        cout << solve(0,0,0,arr) << endl;
    }
    return 0;
}