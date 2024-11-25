#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

vector<int> willgive1(string& shorter, string& longer,int idx){
    int n=shorter.size();
    int m=longer.size();
    char c = shorter[idx];
    int i;
    vector<int> idxs;
    for(i=idx;i<m;++i){
        if(longer[i]==c){
            idxs.push_back(i);
        }
    }
    return idxs;
}

int solve(string& s, string& t){
    int n=s.size();
    int m=t.size();
    if(s[0]!=t[0]){
        return -1;
    }
    
    if(n<m){
        string temp = t.substr(0,n);
        if(temp==s){
            return 1;
        }else{
            int idx = 0;
            for (int i = 0; i < n; ++i) {
                if (s[i] != t[i]) {
                    idx = i;
                    break; 
                }
            }
            vector<int> indexes = willgive1(s,t,idx);
            for(int i : indexes){
                if(s.substr(idx)==t.substr(i)){
                    return 1;
                }
            }
            return 2;
        }
    }else if(n>m){
        string temp = s.substr(0,m);
        if(temp==t){
            return 1;
        }else{
            int idx = 0;
            for (int i = 0; i < m; ++i) {
                if (s[i] != t[i]) {
                    idx = i;
                    break; 
                }
            }
            vector<int> indexes = willgive1(t,s,idx);
            for(int i : indexes){
                if(t.substr(idx)==s.substr(i)){
                    return 1;
                }
            }
            return 2;
        }
    }else{
        return 2;
    }
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int n,m;
        cin>>n>>m;
        string s1,s2;
        cin>>s1>>s2;
        if(s1==s2){
            cout << 0 << endl;
        }else{
            cout << solve(s1,s2) << endl;
        }
    }
    return 0;
}