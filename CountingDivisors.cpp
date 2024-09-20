#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int sieves[1000001];

void sieve(){
    for(int i =1;i<=1000000;i++){
        for(int j = i;j<=1000000;j+=i){
            sieves[j]++;
        }
    }
}

int solve(int x){
    return sieves[x];   
}

int main(){
    int n;
    sieve();
    cin >> n;
    for(int i =0;i<n;i++){
        int x;
        cin >> x;
        cout << solve(x) << endl;
    }
    return 0;
}