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
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int l,r;
        cin >> l >> r;
        int diff = r-l;
        int n=1;
        while(n*(n+1)/2<=diff){
            n++;
        }
        cout << n << endl;
    }
    return 0;
}