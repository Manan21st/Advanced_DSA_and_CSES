#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(vector<pair<int,int>>& arr){
    map<int, int> events;

    for(auto p : arr){
        events[p.first]++;
        events[p.second + 1]--;
    }

    int maxi = 0;
    int current = 0;

    for(auto event : events){
        current += event.second;
        maxi = max(maxi, current);
    }

    return maxi;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin >> test;
    for(int t = 0; t < test; ++t){
        int n;
        cin >> n;
        vector<pair<int,int>> arr(n);
        for(int i = 0; i < n; ++i){
            cin >> arr[i].first >> arr[i].second;
        }
        cout << solve(arr) << endl;
    }
    return 0;
}
