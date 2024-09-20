#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

int solve(){

}

signed main(){
    int test;
    // cin>>test;
    for(int t =0;t<1;++t){
        int n;
        cin >> n;
        bool flag = false;
        vector<string> a(n);
        for(int i=0;i<n;++i){
            cin>>a[i];
        }
        for(int i =1;i<n;++i){
            if(a[i-1]=="sweet" and a[i]=="sweet" and i<n-1){
                flag = true;
                break;
            }
        }
        if(flag){
            cout<<"No"<<endl;
        }
        else{
            cout<<"Yes"<<endl;
        }
    }
    return 0;
}
