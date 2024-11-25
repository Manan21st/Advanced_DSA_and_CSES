#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

string helper(const string &s) {
    string ans;
    for(char c : s) {
        ans += c;
        int size= ans.size();
        if(size >= 2 && ans[size - 2] == 'a' && ans[size - 1] == 'b') {
            ans.pop_back(); 
        }
    }
    return ans;
}

bool solve(string& s, string& t){
    if(s==t){
        return true;
    }
    string new_s = helper(s);
    string new_t = helper(t);
    int n = new_s.size();
    int m = new_t.size();
    if(n!=m){
        return false;
    }
    for(int i=0;i<min(n,m);++i){
        if(new_s[i]!=new_t[i]){
            return false;
        }
    }
    return true;
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int n,m;
        cin >> n >> m;
        string s1,s2;
        cin >> s1 >> s2;
        if(solve(s1,s2)){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}