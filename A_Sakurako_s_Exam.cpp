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
        int a,b;
        cin >> a >> b;
        int s = a + (2*b);
        if((a==0 and b%2!=0)or (b==0 and a%2!=0)){
            cout << "NO" << endl;
            continue;
        }
        if(s%2==0){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}