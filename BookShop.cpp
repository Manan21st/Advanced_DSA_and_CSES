#include <iostream>
#include <vector>
#include <cstring>
#define ll long long
#define mod 1000000007

using namespace std;

int solve(vector<vector<int>>& books, int x, vector<vector<int>>& dp) {
    // if (x == 0 || index >= (int)books.size()) {
    //     return 0;
    // }
    // if (dp[index][x] != -1) {
    //     return dp[index][x];
    // }
    // int ans1 = 0;
    // if (x - books[index][0] >= 0) {
    //     ans1 = solve(books, x - books[index][0], index + 1,dp) + books[index][1];
    // }
    // int ans2 = solve(books, x, index + 1,dp);
    // return dp[index][x] = max(ans1, ans2);

    for(int i=books.size();i>=0;i--){
        for(int j = 0;j<=x;j++){
            if(j==0 || i==books.size()){
                dp[i%2][j]=0;
                continue;
            }
            int ans1 = 0;
            if (j - books[i][0] >= 0) {
                ans1 = dp[(i+1)%2][j - books[i][0]] + books[i][1];
            }
            int ans2 = dp[(i+1)%2][j];
            dp[i%2][j]=max(ans1,ans2);
        }
    }
    return dp[0][x];
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<vector<int>> books(n, vector<int>(2));
    // price
    for (int i = 0; i < n; i++) {
        cin >> books[i][0];
    }
    // pages
    for (int i = 0; i < n; i++) {
        cin >> books[i][1];
    }
    vector<vector<int>> dp(2, vector<int> (x+1,-1));
    cout << solve(books, x,dp) << endl;
    return 0;
}
