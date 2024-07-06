#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

int solve(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k, int l){
    return ((max(a, g) < min(d, j)) && (max(b, h) < min(e, k)) && (max(c, i) < min(f, l)));

}

signed main(){
    int a,b,c,d,e,f,g,h,i,j,k,l;
    cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k>>l;
    if(solve(a,b,c,d,e,f,g,h,i,j,k,l)){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
    return 0;
}
