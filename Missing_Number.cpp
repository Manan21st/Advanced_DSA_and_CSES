#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(){
    return 0;
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test=1;
    // cin>>test;
    for(int t =0;t<test;++t){
        int n;
        cin >> n;
        vector<int> arr(n+1);
        for(int i=1;i<n;++i){
            int x;
            cin >> x;
            arr[x] = 1;
        }
        for(int i=1;i<=n;++i){
            if(arr[i]!=1){
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}