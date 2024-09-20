#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

void solve() {
    string s; cin >> s;
    int n = s.size(), ans = 1;
    v ps(n + 1), cnt_ps(2 * n + 2);

    for (int i = 0; i < n; ++i)
        ps[i+1] = ps[i] + (s[i] == '1' ? 1 : -1);   // prefix sums where 1 = +1 and 0 = -1
    
    for (int i = 1; i <= n; ++i) {
        cnt_ps[ps[i-1] + n] = (cnt_ps[ps[i-1] + n] + i) % mod;
        ans = (ans + cnt_ps[ps[i] + n] * (n - i + 1)) % mod;
    }

    cout << ans - 1 << endl;
}


signed main(){
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        string s;
        cin >> s;
        solve(s);
    }
    return 0;
}
