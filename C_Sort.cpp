#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

int solve(int l, int r, string& a, string&b, vector<vector<int>>& prefixFreqA, vector<vector<int>>& prefixFreqB){
    vector<int> freqA(26,0);
    vector<int> freqB(26,0);
    for(int i=0;i<26;++i){
        freqA[i] = prefixFreqA[r][i] - prefixFreqA[l-1][i];
        freqB[i] = prefixFreqB[r][i] - prefixFreqB[l-1][i];
    }
    int ans = 0;
    for(int i=0;i<26;++i){
        ans += abs(freqA[i]-freqB[i]);
    }
    return ans/2;
}

signed main(){
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int n,q;
        cin >> n >> q;
        string a,b;
        cin>>a>>b;
        vector<vector<int>> prefixFreqA(n + 1, vector<int>(26, 0));
        vector<vector<int>> prefixFreqB(n + 1, vector<int>(26, 0));
        for(int i=0;i<n;++i){
            prefixFreqA[i+1] = prefixFreqA[i];
            prefixFreqA[i+1][a[i]-'a']++;
            prefixFreqB[i+1] = prefixFreqB[i];
            prefixFreqB[i+1][b[i]-'a']++;
        }
        for(int i=0;i<q;++i){
            int l,r;
            cin>>l>>r;
            cout<<solve(l,r,a,b,prefixFreqA,prefixFreqB)<<endl;
        }

    }
    return 0;
}
