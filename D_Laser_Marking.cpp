#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

double dist(double x1, double y1, double x2, double y2) {
    return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

double solve(int idx, double x, double y,vector<vector<pair<int,int>>>& arr, double s, double t, vector<bool> &visited) {
    if (idx == arr.size()) {
        return 0;
    }

    double ans = LLONG_MAX;

    for (int i = 0; i < arr.size(); ++i) {
        int x1 = arr[i][0].first;
        int y1 = arr[i][0].second;
        int x2 = arr[i][1].first;
        int y2 = arr[i][1].second;
        if (!visited[i]) {
            visited[i] = true;
            double print = dist(x1, y1, x2, y2) / t;

            double timeleft = (dist(x, y, x1, y1) / s) + print;
            ans = min(ans, timeleft + solve(idx + 1, x2, y2, arr, s, t, visited));

            double timeright = (dist(x, y, x2, y2) / s) + print;
            ans = min(ans, timeright + solve(idx + 1, x1, y1, arr, s, t, visited));

            visited[i] = false; 
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
    for(int te =0;te<test;++te){
        int n,t,s;
        cin >> n >> s >> t;
        vector<vector<pair<int,int>>> arr(n);
        for(int i=0;i<n;++i){
            int a,b,c,d;
            cin >> a >> b >> c >> d;
            arr[i].push_back({a,b});
            arr[i].push_back({c,d});
        }
        vector<bool> visited(n,false);
        cout << fixed << setprecision(20) << solve(0, 0.0, 0.0, arr, s, t, visited) << endl;
    }
    return 0;
}