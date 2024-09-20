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
        int n;
        cin >> n;
        if(n<100){
            cout << "NO" << endl;
            continue;
        }
        string temp = to_string(n);
        string ten = temp.substr(0,2) ;
        string power  = temp.substr(2,temp.size());
        int x = (power[0])-'0';
        if(ten=="10" and ((power.size()>1 and temp[2]!='0') or x>=2)){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
