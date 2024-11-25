#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

pair<int,int> solve(vector<int>& start, vector<int>& end, int n, int d, int k){
    pair<int,int> ans;
    vector<int> prefix_s(n + 2, 0), prefix_e(n + 2, 0);

    for(int i = 1; i <= n; ++i){
        prefix_s[i] = prefix_s[i - 1] + start[i];
        prefix_e[i] = prefix_e[i - 1] + end[i];
    }

    int max_overlap = -1, min_overlap = k + 1;
    int bro = 1, mom = 1;

    for(int s = 1; s <= n - d + 1; ++s){
        int e = s + d - 1;
        int overlap = prefix_s[e] - prefix_e[s - 1];

        if(overlap > max_overlap){
            max_overlap = overlap;
            bro = s;
        }
        if(overlap < min_overlap){
            min_overlap = overlap;
            mom = s;
        }
    }

    ans = {bro, mom};
    return ans;
}

signed main() {
    // This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test;
    cin >> test;

    for(int t = 0; t < test; ++t){
        int n, d, k;
        cin >> n >> d >> k;

        vector<int> start(n + 2, 0), end(n + 2, 0);

        for(int i = 0; i < k; ++i){
            int l, r;
            cin >> l >> r;
            start[l]++;
            end[r]++;
        }

        pair<int, int> ans = solve(start, end, n, d, k);
        cout << ans.first << " " << ans.second << endl;
    }

    return 0;
}
