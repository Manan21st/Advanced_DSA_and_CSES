#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;
// ***Important - Fermet's Little Theorem

// int solve(int a, int b){
//     if(b==0){
//         return 1;
//     }
//     if(b%2==0){
//         int x = solve(a,b/2);
//         return (x*x)%mod;
//     }
//     return (a*solve(a,b-1))%mod;
// }

int fermet(int a, int b, int m){
    if(b==0){
        return 1;
    }
    if(b%2==0){
        int x = fermet(a,b/2,m);
        return (x*x)%m;
    }
    return (a*fermet(a,b-1,m))%m;
}

signed main(){
    int n;
    cin >> n;
    for(int i  =0 ;i<n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        int r = fermet(b,c,mod-1);
        cout << fermet(a,r,mod) << endl;
    }
    return 0;
}
