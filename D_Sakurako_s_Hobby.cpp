#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

void solve(int start, string& s, vector<int>& arr, vector<bool>& visited, vector<int>& ans) {
    vector<int> path;
    int black = 0;
    int i = start;

    while(!visited[i]) {
        visited[i] = true;
        path.push_back(i);
        if (s[i] == '0') {
            black++;
        }
        i = arr[i] - 1; 
    }

    for(int node : path) {
        ans[node] = black;
    }
}

signed main() {
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    for(int t = 0; t < test; ++t) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for(int i = 0; i < n; ++i) {
            cin >> arr[i];
        }
        string s;
        cin >> s;
        vector<bool> visited(n, false);
        vector<int> ans(n, 0);  
        for (int i = 0; i < n; ++i) {
            if(!visited[i]) {
                solve(i, s, arr, visited, ans);
            }
        }
        for (int i = 0; i < n; ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
