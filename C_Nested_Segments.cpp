#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

template<typename T>
class SegmentTree{
public:
    int n;
    vector<T> tree;
    T identity;
    SegmentTree(int n, T identity){
        this->n = n;
        tree.resize(4*n);
        this->identity = identity;
    }

    void update(int qIdx, T val){
        function<void(int,int,int)> func = [&](int tIdx,int tLeft, int tRight){
            if(tLeft == tRight){
                tree[tIdx] = val;
                return;
            }

            int tMid = tLeft + (tRight-tLeft)/2;
            if(tLeft<=qIdx and qIdx<=tMid){
                func(2*tIdx+1,tLeft,tMid);
            }else{
                func(2*tIdx+2,tMid+1,tRight);
            }

            tree[tIdx] = (tree[2*tIdx+1]+tree[2*tIdx+2]);
        };
        func(0,0,n-1);
    }

    T query(int l, int r){
        function<T(int,int,int)> f = [&](int tL, int tR, int tIdx){
            if(tL>r or tR<l){
                return identity;
            }

            if(l<=tL and tR<=r){
                return tree[tIdx];
            }

            int tM = tL + (tR-tL)/2;
            int left = f(tL,tM,2*tIdx+1);
            int right = f(tM+1,tR,2*tIdx+2);
            return left+right;
        };
        return f(0,n-1,0);
    }
};

int solve(){
    return 0;
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    SegmentTree<int> st(2*n+1,0);
    vector<int> ans(n+1,0);
    map<int,int> mp;
    for(int i =0;i<2*n;++i){
        int x;
        cin >> x;
        if(mp.find(x)!=mp.end()){
            int pos = mp[x];
            mp.erase(x);
            ans[x] = st.query(pos,i);
            st.update(pos,1);
        }else{
            mp[x] = i;
        }
    }
    for(int i=1;i<=n;++i){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
