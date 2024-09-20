#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(vector<int>& weight, int x){
    int ans = weight.size();
    sort(weight.begin(),weight.end());
    int i = 0, j = weight.size()-1;
    while(i<j){
        if(weight[i]+weight[j]<=x){
            ans = min(ans,ans-1);
            i++;
            j--;
        }else{
            j--;
        }
    }
    return ans;
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test=1;
    // cin>>test;
    for(int t =0;t<test;++t){
        int n,x;
        cin >> n >> x;
        vector<int> a(n);
        for(int i =0;i<n;++i){
            cin >> a[i];
        }
        cout << solve(a,x) << endl;
    }
    return 0;
}
