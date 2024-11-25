#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int solve(){
    return 0;
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<int> height(n);
    for(int i = 0; i < n; ++i){
        cin >> height[i]; 
    }

    vector<int> result(n, 0);  
    stack<int> st;  

    for(int i = n - 1; i >= 0; --i){
        while(!st.empty() && height[st.top()] < height[i]){
            result[i]++;
            st.pop(); 
        }
        
        result[i] += st.size();
        st.push(i);
    }

    for(int i = 0; i < n; ++i){
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
