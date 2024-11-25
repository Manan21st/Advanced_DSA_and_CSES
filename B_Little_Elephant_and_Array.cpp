#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'
#define v vector

using namespace std;

struct Query {
    int l, r, id;
};

const int S = 200;
 
bool cmp(Query &a, Query &b)
{
    if(a.l / S != b.l / S) {
        return a.l / S < b.l / S;
    }
    return a.r > b.r;
}

const int N = 1e6 + 10;
int a[N + 1], compressed[N + 1], freq[N + 1];

int ans = 0;
void add(int idx)
{
    int val = compressed[idx];
    ans-=(freq[val]==a[idx]);
    freq[val]++;
    ans+=(freq[val]==a[idx]);
}
 
void remove(int idx)
{
    int val = compressed[idx];
    ans-=(freq[val]==a[idx]);
    freq[val]--;
    ans+=(freq[val]==a[idx]);
}

void solve()
{
    int n, q; cin >> n;
    cin >> q;
    for(int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
 
    map<int, int> mp;
    for(int i = 0; i < n; ++i)
    {
        if(mp.count(a[i]))
        {
            compressed[i] = mp[a[i]];
        }
        else
        {
            compressed[i] = mp.size();
            mp[a[i]] = mp.size();
        }
    }
 
    v<Query> queries(q);
    for(int i = 0; i < q; ++i) {
        cin >> queries[i].l >> queries[i].r;
        queries[i].l--;
        queries[i].r--;
        queries[i].id = i;
    }
    sort(queries.begin(), queries.end(), cmp);
    v<int> result(q);
    for(int i = 0, L = 0, R = -1; i < q; ++i) {
        while(R < queries[i].r) add(++R);
        while(L > queries[i].l) add(--L);
        while(R > queries[i].r) remove(R--);
        while(L < queries[i].l) remove(L++);
        result[queries[i].id] = ans;
    }
    for(int i = 0; i < q; ++i) {
        cout << result[i] << endl;
    }
}  

signed main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t = 1;
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}
