#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(int n){
    int sum =0;
    while(n>0){
        sum+=n%10;
        n/=10;
    }
    return sum;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int n;
        cin>>n;
        cout<<solve(n)<<endl;
    }
    return 0;
}
