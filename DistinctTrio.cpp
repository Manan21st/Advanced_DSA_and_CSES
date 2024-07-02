#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

ll solve(vector<ll>& array){
    ll n = array.size();
    ll count =0;
    
    map<ll,ll> mp;

    for(ll i =0; i<n;i++){
        mp[array[i]]++;
    }

    for(auto temp : mp){
        
    }
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