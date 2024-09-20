#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

int solve(){
    return 0;
}

signed main(){
    int test;
    // cin>>test;
    for(int t =0;t<1;++t){
        int r,c;
        cin >> r >> c;
        int startx,starty;
        cin >> startx >> starty;
        --startx;
        --starty;
        vector<vector<char>> a(r,vector<char>(c));
        for(int i=0;i<r;++i){
            for(int j=0;j<c;++j){
                cin>>a[i][j];
            }
        }
        string x;
        cin>>x;
        vector<pair<int, int>> directions(128);
        directions['L'] = {0, -1};
        directions['R'] = {0, 1};
        directions['U'] = {-1, 0};
        directions['D'] = {1, 0};
        for(char move : x){
            int newx = startx + directions[move].first;
            int newy = starty + directions[move].second;
            if(newx>=0 and newx<r and newy>=0 and newy<c and a[newx][newy]=='.'){
                startx = newx;
                starty = newy;
            }
        }
        cout<<startx+1<<" "<<starty+1<<endl;
    }
    return 0;
}
