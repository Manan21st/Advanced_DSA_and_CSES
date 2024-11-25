#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

vector<bool> sieve(int limit) {
    vector<bool> is_prime(limit + 1, true);  
    is_prime[0] = is_prime[1] = false;  

    for (int i = 2; i * i <= limit; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j <= limit; j += i) {
                is_prime[j] = false;  
            }
        }
    }

    return is_prime;  
}

vector<vector<int>> solve(int n, int m) {
    vector<vector<int>> ans(n, vector<int>(m));

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j) {
            ans[i][j] = 2;
        }
    }

    for(int i = 0; i < min(n, m); ++i){
        ans[i][i] = 3;
    }
    for(int i = 0; i < m; ++i){
        if(n <= i) {
            ans[0][i] = 3;
        }
    }
    for(int i = 0; i < n; ++i){
        if(m <= i) {
            ans[i][0] = 3;
        }
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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> result = solve(n, m);
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < m; ++j){
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
