#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(vector<int>& arr, int r){
    int n = arr.size();
    int ans=0;
    for(int i=0;i<n;++i){
        int p = arr[i]/2;
        ans+=(p*2);
        r-=p;
    }

    int total = 0;
    for(int i=0;i<n;++i){
        total+= (arr[i]%2);
    }

    if(total<=r){
        ans+=total;
    }else{
        ans += ((2*r)-total);
    }
    return ans;
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int n,r;
        cin >> n >> r;
        vector<int> arr(n);
        for(int i=0;i<n;++i){
            cin >> arr[i];
        }
        cout<<solve(arr,r)<<endl;
    }
    return 0;
}