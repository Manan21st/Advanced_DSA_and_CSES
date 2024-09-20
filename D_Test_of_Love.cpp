#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

bool solve(int n, int m, int k, string& s){

    int curr = m - 1; 
    int wrong = 0; 
    int fail = 0; 

    for(int i = 0;i<s.size();i++){
        char ch = s[i];
        if(ch == 'W'){
            if (curr <= 0) {
                wrong++;
            }
        } 
        else if (ch == 'L'){
            curr = m; 
        }else{
            if(curr <= 0){
                fail++;
            }
        }
        curr--;
    }

    if(wrong > k){
        fail++;
    }
    return fail==0;
}

signed main(){
    int test;
    cin >> test;
    for(int i =0;i<test;i++){
        int n,m,k;
        cin >> n >> m >> k;
        string s;
        cin >> s;
        if(solve(n,m,k,s)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
