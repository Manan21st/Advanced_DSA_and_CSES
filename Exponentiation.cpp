#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

int solve(int a, int b){
    if(b==0){
        return 1;
    }
    if(b%2==0){
        int x = solve(a,b/2);
        return (x*x)%mod;
    }
    return (a*solve(a,b-1))%mod;
}

signed main(){
    int n;
    cin >> n;
    for(int i  =0 ;i<n;i++){
        int a,b;
        cin >> a >> b;
        cout << solve(a,b)%mod << endl;
    }
    return 0;
}
