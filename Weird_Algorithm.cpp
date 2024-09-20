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
    int test=1;
    // cin>>test;
    for(int t =0;t<test;++t){
        int n;
        cin >> n;
        while(n!=1){
            cout << n << " ";
            if(n%2==0){
                n/=2;
            }else{
                n = n*3 + 1;
            }
        }
        cout << 1 << endl;
    }
    return 0;
}