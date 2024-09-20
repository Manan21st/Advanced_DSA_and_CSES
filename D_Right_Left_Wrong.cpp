#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(vector<int>& values, string& s){
    int ans =0;
    int n = values.size();
    vector<int> prefix(n,0);
    prefix[0] = values[0];
    for(int i=1;i<n;++i){
        prefix[i] = prefix[i-1] + values[i];
    }
    int right = n-1;
    for(int i =0;i<n;++i){
        if(s[i]=='L'){
            while(right>i and s[right]=='L'){
                --right;
            }
            if(right>i){
                ans += (i == 0) ? prefix[right] : prefix[right] - prefix[i - 1];
                --right;
            }
        }
    }
    return ans;
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int n;
        cin >> n;
        vector<int> values(n); 
        for(int i =0;i<n;++i){
            cin >> values[i];
        }
        string s;
        cin >> s;
        cout << solve(values,s) << endl;
    }
    return 0;
}
