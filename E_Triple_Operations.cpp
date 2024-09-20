#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

vector<int> v(3*1e5+1,0);
vector<int> prefix(3*1e5+1,0);

void precomp(){
    for(int i=1;i<=3*1e5;++i){
        int x=i;
        while(true){
            if(x==0){
                break;
            }
            x/=3;
            v[i]++;
        }
    }
}

int solve(int l, int r){
    return v[l]+prefix[r]-prefix[l-1];
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    precomp();

    for(int i=1;i<=3*1e5;++i){
        prefix[i] = prefix[i-1]+v[i];
    }

    for(int t =0;t<test;++t){
        int l,r;
        cin >> l >> r;
        cout << solve(l,r) << endl;
    }
    return 0;
}
