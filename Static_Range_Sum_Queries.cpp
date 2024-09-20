#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

vector<int> solve(vector<int> value,vector<vector<int>> queries){
    int n = value.size();
    int q = queries.size();
    vector<int> prefix(n+1,0);
    vector<int> ans;
    for(int i =1;i<=n;i++){
        prefix[i] = prefix[i-1]+value[i-1];
    }
    for(int i =0;i<q;i++){
        if(queries[i][0]>0){
            ans.push_back(prefix[queries[i][1]]-prefix[queries[i][0]-1]);
        }
        else{
            ans.push_back(prefix[queries[i][1]]);
        }
    }
    return ans;
}

signed main(){
    int n,q;
    cin >> n >> q;
    vector<int> value(n);
    for(int i =0;i<n;i++){
        cin >> value[i];
    }
    vector<vector<int>> queries(q,vector<int>(2));
    for(int i =0;i<q;i++){
        cin >> queries[i][0] >> queries[i][1];
    }
    vector<int> toprint;
    toprint = solve(value,queries);
    for(int i =0;i<toprint.size();i++){
        cout << toprint[i] << endl;
    }
    return 0;
}
