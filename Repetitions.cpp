#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(){
    return 0;
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test=1;
    // cin>>test;
    for(int t =0;t<test;++t){
        string s;
        cin >> s;
        int n = s.size();
        int ans = 1;
        int count = 1;
        for(int i=1;i<n;++i){
            if(s[i]==s[i-1]){
                count++;
            }else{
                count = 1;
            }
            ans = max(ans,count);
        }
        cout << ans << endl;
    }
    return 0;
}