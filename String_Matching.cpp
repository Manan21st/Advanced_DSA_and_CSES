#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int power(int a, int b, int m){
    if(b==0){
        return 1;
    }
    if(b%2==0){
        int x = power(a,b/2,m);
        return (x*x)%m;
    }
    return (a*power(a,b-1,m))%m;
}

int modInv(int a, int m){
    return power(a,m-2,m);
}

class Hash{
    int n;
    const int p1 = 31, p2 = 37;
    const int mod1 = 1e9+7, mod2 = 1e9+9;
    vector<int> arr1, arr2;
    vector<int> modInv1, modInv2;
public:
    Hash(string& s){
        n = s.size();
        arr1.resize(n);
        arr2.resize(n);
        modInv1.resize(n);
        modInv2.resize(n);
        int pow1= 1, pow2 = 1;
        for(int i=0;i<n;++i){
            arr1[i] = ((s[i]-'a'+1)*pow1)%mod1;
            arr2[i] = ((s[i]-'a'+1)*pow2)%mod2;
            pow1 = (pow1*p1)%mod1;
            pow2 = (pow2*p2)%mod2;
        }
        for(int i=1;i<n;++i){
            arr1[i] = (arr1[i]+arr1[i-1])%mod1;
            arr2[i] = (arr2[i]+arr2[i-1])%mod2;
        }

        pow1 = modInv(p1,mod1);
        pow2 = modInv(p2,mod2);

        modInv1[0] = 1;
        modInv2[0] = 1;

        for(int i=1;i<n;++i){
            modInv1[i] = (modInv1[i-1]*pow1)%mod1;
            modInv2[i] = (modInv2[i-1]*pow2)%mod2;
        }
    }

    pair<int,int> substr(int l, int r){
        if(r>=n or l<0){
            return {-1,-1};
        }
        int ans1 = arr1[r] - (l ? arr1[l-1] : 0);
        ans1 = (ans1+mod1)%mod1;
        int ans2 = arr2[r] - (l ? arr2[l-1] : 0);
        ans2 = (ans2+mod2)%mod2;

        ans1 *= modInv1[l];
        ans1 %= mod1;
        ans2 *= modInv2[l];
        ans2 %= mod2;

        return {ans1,ans2};
    }
};

int solve(string& s, string& t){
    int n = s.size();
    int m = t.size();
    if(n<m){
        return 0;
    }
    int ans=0;
    Hash h1(s), h2(t);
    for(int i=0;i<n-m+1;++i){
        if(h1.substr(i,i+m-1)==h2.substr(0,m-1)){
            ans++;
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
        string s1,s2;
        cin >> s1 >> s2;
        cout << solve(s1,s2) << endl;
    }
    return 0;
}