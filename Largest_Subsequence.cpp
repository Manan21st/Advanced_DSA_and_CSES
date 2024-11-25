#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(int n, string& s){
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == s[0]) {
            ans = max(ans, i + 1);
        }
        if (s[i] == s[n - 1]) {
            ans = max(ans, n - i);
        }
    }
    
    return ans;
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin >> test;
    for (int t = 0; t < test; ++t) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << solve(n,s) << endl;
    }
    
    return 0;
}
