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
        int n, x, y;
        cin >> n >> x >> y;
        vector<pair<int,int>> a(n);
        for(int i=0;i<n;++i){
            cin >> a[i].first;
        }
        for(int i=0;i<n;++i){
            cin >> a[i].second;
        }
        
        sort(a.begin(),a.end(),greater<pair<int,int>>());

        int min_sweet=0;
        int min_salty=0;
        int count=0;
        for(int i=0;i<n;++i){
            if(min_sweet<=x and min_salty<=y){
                min_sweet+=a[i].first;
                min_salty+=a[i].second;
                ++count;
            }else{
                break;
            }
        }

        sort(a.begin(),a.end(),[&](pair<int,int> a, pair<int,int> b){
            return a.second>b.second;
        });

        int min_sweet_rev=0;
        int min_salty_rev=0;
        int count_rev=0;
        for(int i=0;i<n;++i){
            if(min_sweet_rev<=x and min_salty_rev<=y){
                min_sweet_rev+=a[i].first;
                min_salty_rev+=a[i].second;
                ++count_rev;
            }else{
                break;
            }
        }
        cout<<min(count,count_rev)<<endl;
    }
    return 0;
}
