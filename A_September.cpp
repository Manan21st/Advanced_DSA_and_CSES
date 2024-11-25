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
        vector<string> arr(12);
        for(int i=0;i<12;++i){
            cin>>arr[i];
        }
        int count = 0;
        for(int i=1;i<=12;++i){
            if(arr[i-1].size()==i){
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}