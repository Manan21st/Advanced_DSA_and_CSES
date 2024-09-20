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
        if(n==1){
            cout << 1 << endl;
            continue;
        }
        if(n<4){
            cout << "NO SOLUTION" << endl;
            continue;
        }
        vector<int> arr;
        for (int i = 2; i <= n; i += 2) {
            arr.push_back(i);
        }
        for (int i = 1; i <= n; i += 2) {
            arr.push_back(i);
        }
        for (int num : arr) {
            cout << num << " ";
        }
        cout << endl;

    }
    return 0;
}