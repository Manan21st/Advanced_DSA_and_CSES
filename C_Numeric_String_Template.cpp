#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

bool solve(vector<int>& a, string& s) {
    map<int, char> a_to_s;
    map<char, int> s_to_a; 

    int n = a.size();
    for (int i = 0; i < n; ++i) {
        int num = a[i];
        char ch = s[i];

        if (a_to_s.count(num)) {
            if (a_to_s[num] != ch) return false;
        } else {
            a_to_s[num] = ch;
        }

        if (s_to_a.count(ch)) {
            if (s_to_a[ch] != num) return false;
        } else {
            s_to_a[ch] = num;
        }
    }

    return true;
}



signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int n;
        cin >> n;
        vector<int> numbers(n);
        for(int i =0;i<n;++i){
            cin >> numbers[i];
        }
        int m;
        cin >> m;
        for(int i =0;i<m;++i){
            string s;
            cin >> s;
            if(s.size()!=n or !solve(numbers,s)){
                cout << "NO" << endl;
            }else{
                cout << "YES" << endl;
            }
        }
        
    }
    return 0;
}
