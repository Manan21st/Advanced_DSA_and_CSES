#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

vector<int> solve(multiset<int>& tickets, vector<int>& cust){
    vector<int> ans;
    for(int i =0;i<cust.size();++i){
        auto it = tickets.upper_bound(cust[i]);
        if(it==tickets.begin()){
            ans.push_back(-1);
        }else{
            ans.push_back(*(--it));
            tickets.erase(it);
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
        int n,m;
        cin >> n >> m;
        multiset<int> tickets;
        vector<int> b(m);
        for(int i =0;i<n;++i){
            int x;
            cin >> x;
            tickets.insert(x);
        }
        for(int i =0;i<m;++i){
            cin >> b[i];
        }
        vector<int> ans = solve(tickets,b);
        for(auto val : ans){
            cout << val << endl;
        }
    }
    return 0;
}
