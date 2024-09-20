#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

int solve(){
    return 0;
}

signed main(){
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int n;
        cin >> n;
        int ans =n/4;
        int temp = n%4;
        if(temp>0){
            ans+= temp/2;
        }
        cout<<ans<<endl;
    }
    return 0;
}
