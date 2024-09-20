#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

int solve(int n, string& str){
    int zeroes=0,ones=0;
    char last='1';
    for(int i=0;i<n;i++){
        if(str[i]=='1'){
            ones++;
        }else if(str[i]=='0' and last=='0'){
            continue;
        }else{
            zeroes++;
        }
        last=str[i];
    }
    return ones>zeroes;
}

signed main(){
    int test;
    cin >> test;
    for(int i=0;i<test;i++){
        int n;
        string s;
        cin >> n >> s;
        if(solve(n,s)){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
    return 0;
}
