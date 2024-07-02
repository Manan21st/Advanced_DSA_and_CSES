#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

int CoinCombinations1(vector<int>& coins, int target) {
    vector<int> dp(target + 1, 0);
    dp[0] = 1; // Base case: There's one way to produce the sum 0 (by using no coins)

    for (int i = 1; i <= target; ++i) {
        for (int num : coins) {
            if (i - num >= 0) {
                dp[i] = (dp[i] + dp[i - num]) % mod;
            }
        }
    }
    return dp[target];
}

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> coins(n);
    for (int i = 0; i < n; ++i) {
        cin >> coins[i];
    }

    cout << CoinCombinations1(coins, target) << endl;

    return 0;
}
