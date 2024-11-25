#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int dp[22][1 << 21];

int solve(int man, int mask, vector<vector<int>> &arr)
{
    int n = arr.size();
    if (man >= n)
    {
        return 1;
    }
    if (dp[man][mask] != -1)
    {
        return dp[man][mask];
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if ((mask & (1 << i)) == 0 and arr[man][i] == 1)
        {
            ans += solve(man + 1, (mask | (1 << i)), arr);
            ans %= mod;
        }
    }
    return dp[man][mask] = ans % mod;
}

signed main()
{
    // This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1;
    // cin>>test;
    for (int t = 0; t < test; ++t)
    {
        memset(dp, -1, sizeof(dp));
        int n;
        cin >> n;
        vector<vector<int>> arr(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                cin >> arr[i][j];
            }
        }
        cout << solve(0, 0, arr) % mod << endl;
    }
    return 0;
}
