#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

void solve(string& s, string& target){
    int i =0;
    int j =0;
    while(i<s.size() and j<target.size()){
        if(s[i]=='?'){
            s[i] = target[j];
            i++;
            j++;
            continue;
        }
        if(s[i] == target[j]){
            i++;
            j++;
        }else{
            i++;
        }
    }
    cout << (j==target.size()?"YES":"NO") << endl;
    if(j==target.size()){
        for(int i=0;i<s.size();++i){
            if(s[i]=='?'){
                s[i] = 'd';
            }
        }
        cout << s << endl;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        string s,target;
        cin>>s;
        cin>>target;
        if(target.size()>s.size()){
            cout << "NO" << endl;
            continue;
        }
        solve(s,target);
    }
    return 0;
}
