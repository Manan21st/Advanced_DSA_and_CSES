#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll solve(vector<ll>& array,int targetSum){
    ll n = array.size();
    ll count =0;
    ll prefixSum=0;
    map<ll,ll> mp;

    for(ll i =0;i<n;i++){
        prefixSum+=array[i];
        if(prefixSum==targetSum){
            count++;
        }
        count+=mp[prefixSum-targetSum];
        mp[prefixSum]++;
    }
    return count;
}

int main(){
    ll n,x;
    cin >> n;
    cin >> x;
    vector<ll> array(n);
    for(ll i=0;i<n;i++){
        cin >> array[i]; 
    }
    cout << solve(array,x) << endl;
    return 0;
}