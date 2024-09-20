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
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int x,y,k;
        cin>>x>>y>>k;
        for(int i=0;i<k/2;++i){
            int xc = x-i-1;
            int yc = y-i-1;
            cout<<xc<<" "<<yc<<endl; 
            cout<<xc+(2*i)+2<<" "<<yc+(2*i)+2<<endl;
        }
        if(k%2==1){
            cout<<x<<" "<<y<<endl;
        }
    }
    return 0;
}
