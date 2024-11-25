#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

bool isPalin(string& s){
    int n = s.size();
    for(int i=0;i<n/2;++i){
        if(s[i]!=s[n-i-1]){
            return false;
        }
    }
    return true;
}

bool helper(string& s){
    int n = s.size();
    for (int i = 0; i < n; i+=2) {
        if (s[i] != s[0] or s[i+1]!=s[1]) {
            return false; 
        }
    }
    return true;
}

int solve(string& s){
    int n = s.size();
    if(isPalin(s)){
        return 0;
    }
    if(n%2==0 and helper(s)){
        return -1;
    }
    return 1;
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
        string s;
        cin >> s;
        cout << solve(s) << endl;
    }
    return 0;
}
