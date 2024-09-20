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
        set<int> st;
        for(int i =0;i<n;++i){
            int x;
            cin >> x;
            st.insert(x);
        }
        cout << st.size() << endl;
    }
    return 0;
}
