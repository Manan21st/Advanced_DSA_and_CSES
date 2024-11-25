#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

vector<int> solve(int n, int m, int k, vector<int>& arr){
    vector<int> ans(n);
    int total =0;
    for(int i=0;i<n;++i){
        total+=arr[i];
    }

    int votes = k-total;

    vector<int> temp = arr;
    sort(temp.begin(),temp.end());

    for(int i=0;i<n;++i){
        int diff = n - (upper_bound(temp.begin(),temp.end(),arr[i])-temp.begin());
        if(diff<m){
            ans[i]=0;
        }else{
            int x = max(0ll,temp[n-m] - arr[i]+1);
            if(votes>=x){
                ans[i]=x;
            }else{
                ans[i]=-1;
            }
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
        int n,m,k;
        cin >> n >> m >> k;
        vector<int> arr(n);
        for(int i=0;i<n;++i){
            cin >> arr[i];
        }
        vector<int> ans = solve(n,m,k,arr);
        for(int i=0;i<ans.size();++i){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}