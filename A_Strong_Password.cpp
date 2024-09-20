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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        string s;
        cin >> s;
        if(s.size()<2){
            s.push_back(s[0]=='z' ? 'a':s[0]+1);
        }else{
            for(int i=1;i<s.size();++i){
                if(s[i]==s[i-1]){
                    char ch = s[i]+1;
                    if(s[i]=='z'){
                        ch = 'a';
                    }
                    s.insert(i, 1, ch);
                    break;
                }else if(i==s.size()-1){
                    s.push_back(s[i]=='z' ? 'a':s[i]+1);
                    break;
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}
