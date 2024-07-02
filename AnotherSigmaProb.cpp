#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll mod =998244353;

ll solve(vector<ll>& array){
    ll n = array.size();
    ll ans = 0;
    ll sum = 0;
    vector<ll> pow(13);
    pow[0]=1;

    for(ll i =0;i<13;i++){
        pow[i] = (10 * pow[i-1])%mod;
    }
    for(ll i=0;i<n;i++){
        ans += (sum * pow[to_string(array[i]).size()])%mod;
        ans += (array[i]*i)%mod;
        sum+=array[i];
        sum%=mod;
    }

    return ans%mod;
}

int main(){
    ll n;
    cin >> n;
    vector<ll> array(n);
    for(ll i=0;i<n;i++){
        cin >> array[i]; 
    }
    cout << solve(array) << endl;
    return 0;
}