#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MOD = 1e9 + 7;

int dice_combinations_recursive(int curr, vector<int>& dp, int target) {
    if (target == curr) {
        return 1;
    }
    if (curr > target) {
        return 0;
    }
    if (dp[curr] != -1) {
        return dp[curr];
    }
    int ans = 0;
    for (int i = 1; i <= 6; ++i) {
        ans = (ans + dice_combinations_recursive(curr + i, dp, target)) % MOD;
    }
    dp[curr] = ans;
    return dp[curr];
}

int dice_combinations(int target) {
    vector<int> dp(target + 1, 0);
    for (int i = target; i >= 0; --i) {
        for (int j = 1; j <= 6; ++j) {
            if (i == target) {
                dp[i] = 1;
                break;
            }
            if (i + j <= target) {
                dp[i] = (dp[i] + dp[i + j]) % MOD;
            }
        }
    }
    return dp[0];
}

int main() {
    int n;
    cin >> n;
    vector<int> dp(n + 1, -1);
    cout << dice_combinations(n) << endl;
    return 0;
}
