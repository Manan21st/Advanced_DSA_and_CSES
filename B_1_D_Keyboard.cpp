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
        int count =0;

        vector<int> arr(26);
        for(int i=0;i<s.size();++i){
            arr[s[i]-'A'] = i;
        }
        int last = arr[0];

        for(int i=1;i<26;++i){
            count += (abs(arr[i]-last));
            last = arr[i];
        }
        cout << count << endl;
    }
    return 0;
}