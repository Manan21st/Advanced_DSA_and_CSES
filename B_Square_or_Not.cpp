#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

bool solve(int n, string& s) {
    int side = sqrt(n);

    if (side*side != n) {
        return false;
    }

    vector<vector<char>> grid(side, vector<char>(side));
    for (int i = 0; i < n; i++) {
        grid[i / side][i % side] = s[i];
    }

    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            if (i == 0 || j == 0 || i == side - 1 || j == side - 1) {
                if (grid[i][j] != '1') {
                    return false;
                }
            } else {
                if (grid[i][j] != '0') {
                    return false;
                }
            }
        }
    }

    return true;
}


signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int n;
        cin >> n;
        string s;
        cin >> s;
        if(solve(n,s)){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}

