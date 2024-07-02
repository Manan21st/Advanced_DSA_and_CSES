// #include <iostream>
// #include <bits/stdc++.h>

using namespace std;

int solve(vector<int>& nums){
    int n = nums.size();
    int ans = 0;
    
}

int main(){
    int t;
    cin >> t;
    for(int i = 0; i < t;i++){
        int n;
        vector<int> num;
        cin >> n;
        for(int j = 0;j<n;j++){
            int x;
            cin >> x;
            num.push_back(x);
        }
        cout << solve(num) << endl;
    }
    return 0;
}