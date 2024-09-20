#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

int solve(int n, int k){
    if(n==1){
        return 0;
    }
    if(k>=n){
        return 1;
    }
    int ans=0;
    ans+=(n-1)/(k-1);
    ans+=min((n-1)%(k-1),1LL);
    return ans;

}

signed main(){
    int test;
    cin >> test;
    for(int i = 0; i < test; i++){
        int n,k;
        cin >> n >> k;
        cout << solve(n,k) << endl;
    }
    return 0;
}
