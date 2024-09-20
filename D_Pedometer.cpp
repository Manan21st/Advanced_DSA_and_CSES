#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(int n, const vector<int>& a, int m) {
    vector<int> ps(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        ps[i] = ps[i - 1] + a[(i - 1)];
    }

    int total_dist = ps[n];
    map<int, int> cnts;
    int cnt = 0;
    cnts[0] = 1;
    for(int i = 1; i <= n; ++i){
        int rem = ps[i] % m;
        cnt += cnts[rem];
        cnts[rem]++;
    }
    return cnt;
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test=1;
    // cin>>test;
    for(int t =0;t<test;++t){
        int n,m;
        cin>>n>>m;
        vector<int> arr(n);
        for(int i =0;i<n;++i){
            cin>>arr[i];
        }
        cout << solve(n, arr, m) << endl;
    }
    return 0;
}
