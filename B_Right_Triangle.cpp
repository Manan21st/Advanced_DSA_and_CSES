#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

int solve(int xa,int ya,int xb, int yb){
    return ((xa - xb)*(xa - xb)) + ((ya - yb)*(ya - yb));
}

signed main(){
    int xa,ya,xb,yb,xc,yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    int a = solve(xa,ya,xb,yb);
    int b = solve(xb,yb,xc,yc);
    int c = solve(xa,ya,xc,yc);
    if(a+b==c || a+c==b || b+c==a){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
