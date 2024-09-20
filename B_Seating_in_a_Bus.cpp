#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

bool solve(vector<int>& seats){
    int n = seats.size();
    vector<bool> visited(n+3,false);
        bool flag = false;
        visited[seats[0]] = true;
        for(int i =1;i<n;++i){
            int seat = seats[i];
            if(visited[seat+1] or visited[seat-1]){
                visited[seat] = true;
            }else{
                return false;
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
        vector<int> seats(n);
        for(int i =0;i<n;++i){
            cin >> seats[i];
        }
        
        if(!solve(seats)){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
    return 0;
}
