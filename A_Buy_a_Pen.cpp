#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

int solve(){

}

signed main(){
    int r,g,b;
    string color;
    cin >> r >> g >> b;
    cin >> color;
    transform(color.begin(),color.end(),color.begin(),::tolower);
    int ans=0;
    if(color=="red"){
        ans = min(g,b);
    }else if(color=="green"){
        ans = min(r,b);
    }else if(color=="blue"){
        ans = min(r,g);
    }
    cout<< ans << endl;
    return 0;
}
