#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

bool isSame(vector<int>& arr){
    int n = arr.size();
    int x = arr[0];
    for(int i=1;i<n;++i){
        if(arr[i]!=x){
            return false;
        }
    }
    return true;
}

int solve(vector<int>& arr, int k){
    int n = arr.size();
    int ans =2;

    if(isSame(arr) and arr[0]==k){
        return 0;
    }else if(isSame(arr)){
        return 1;
    }
    
    map<int, vector<int>> mp;
    for(int i=0;i<n;++i){
        mp[arr[i]].push_back(i);
    }

    if(mp.count(k) && mp.size() == 2){
        for(auto x: mp){
            if (x.first == k) continue;
            bool continuous = true;
            for (int i = 1; i < x.second.size(); ++i) {
                if (x.second[i] != x.second[i - 1] + 1) {
                    continuous = false;
                    break;
                }
            }
            if (continuous) {
                return 1;
            }
        }
        return 1;
    }

    int gcd =arr[0];
    for(int i=0;i<n;++i){
        gcd = __gcd(gcd,arr[i]);
    }

    if(gcd==k or gcd%k==0){
        return 1;
    }

    return ans;
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int n,k;
        cin >> n >> k;
        vector<int> arr(n);
        for(int i=0;i<n;++i){
            cin >> arr[i];
        }
        cout << solve(arr,k) << endl;
    }
    return 0;
}