#include <iostream>
#include <bits/stdc++.h>

#define ll long long
using namespace std;

//counting subarray with k distinct values.

ll solve(vector<ll>& array,ll k){
    ll n = array.size();
    ll count=0;
    ll l=0;
    ll r=0;
    unordered_map<ll,ll> mp;
    while(r<n){
        mp[array[r]]++;
        while(mp.size()>k){
            mp[array[l]]--;
            if(mp[array[l]]==0){
                mp.erase(array[l]);
            }
            l++;
        }
        count+=r-l+1;
        r++;
    }
    return count;
}

int main(){
    ll n,k;
    cin >> n;
    cin >> k;
    vector<ll> array(n);
    for(ll i=0;i<n;i++){
        cin >> array[i]; 
    }
    cout << solve(array,k) << endl;
    return 0;
}