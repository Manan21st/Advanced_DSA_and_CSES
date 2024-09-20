#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(const string& s) {
    int n = s.size();
    stack<pair<char,int>> st; 
    int cost = 0;

    for (int i = 0; i < n;++i) {
        if((s[i]=='_' and st.empty()) or s[i]=='('){
            st.push({s[i],i+1});
        }
        else if(s[i]==')'){
            auto top = st.top();
            st.pop();
            cost += (i+1-top.second);
        }else if(s[i]=='_' and !st.empty()){
            auto top = st.top();
            st.pop();
            cost += (i+1-top.second);
        }
    }

    return cost;
}




signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int n; 
        cin >> n;
        string s; 
        cin >> s;
        int ans = solve(s);
        cout << ans << endl;
    }
    return 0;
}
