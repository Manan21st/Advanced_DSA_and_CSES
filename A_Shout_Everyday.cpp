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
    int test =1;
    // cin>>test;
    for(int t =0;t<test;++t){
        int A,B,C;
        cin>>A>>B>>C;
            if (B < C) {
                if (B <= A && A < C) {
                    cout << "No" << endl; 
                } else {
                    cout << "Yes" << endl;  
                }
            } else {
                if (A >= B || A < C) {
                    cout << "No" << endl;  
                } else {
                    cout << "Yes" << endl; 
                }
            }
    }
    return 0;
}
