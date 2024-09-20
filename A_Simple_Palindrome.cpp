#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

string solve(vector<char>& vowels,int n){
    string s;
    if(n<=5){
        for(int i=0;i<n;++i){
            s+=vowels[i];
        }
        return s;
    }
    int extra = n%5;
    int times = n/5;
    for(int i=0;i<5;++i){
        int idx = i%5;
        int j =0;
        while(j<times){
            s+=vowels[idx];
            ++j;
        }
        if(extra>0){
            s+=vowels[idx];
            --extra;
        }
    }

    return s;
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
        vector<char> vowels(5);
        vowels[0]='a';
        vowels[1]='e';
        vowels[2]='i';
        vowels[3]='o';
        vowels[4]='u';
        cout<<solve(vowels,n)<<endl;
    }
    return 0;
}