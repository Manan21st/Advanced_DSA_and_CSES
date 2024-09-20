#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(vector<string>& arr){
    int count =0;
    int n = arr[0].size();
    for(int i=0;i<2;++i){
        for(int j=0;j<n;++j){
            if(arr[i][j]=='.'){
                if(i==0 and arr[i+1][j]=='.' and j+1<n and arr[i][j+1]=='.' and j-1>=0 and arr[i][j-1]=='.' and arr[i+1][j+1]=='x' and arr[i+1][j-1]=='x'){
                    count++;
                }
                if(i==1 and arr[i-1][j]=='.' and j+1<n and arr[i][j+1]=='.' and j-1>=0 and arr[i][j-1]=='.' and arr[i-1][j+1]=='x' and arr[i-1][j-1]=='x'){
                    count++;
                }
            }
        }
    }
    return count;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int n;
        cin >> n;
        vector<string> arr(2);
        cin >> arr[0] >> arr[1];
        int ans = solve(arr);
        cout << ans << endl;
    }
    return 0;
}
