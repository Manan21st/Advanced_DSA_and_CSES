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
    vector<bool> lazy;
    SegmentTree(int n){
        this->n = n;
        tree.resize(4*n);
        lazy.resize(4*n);
    }

    void propogate(int tL, int tR, int tIdx){
        if(!lazy[tIdx] or tL==tR){
            return;
        }
        tree[2*tIdx+1] = tree[tIdx];
        tree[2*tIdx+2] = tree[tIdx];
        lazy[2*tIdx+1] = true;
        lazy[2*tIdx+2] = true;
        lazy[tIdx] = false;
        tree[tIdx] = 0;
    }

    void update(int l, int r, T x){
        function<void(int,int,int)> f = [&](int tL, int tR, int tIdx){
            propogate(tL,tR,tIdx);
            if(tL>r or tR<l){
                return;
            }
            if(tL>=l and tR<=r){
                tree[tIdx] = x;
                lazy[tIdx] = true;
                return;
            }
            int tM = tL + (tR-tL)/2;
            f(tL,tM,2*tIdx+1);
            f(tM+1,tR,2*tIdx+2);
        };
        f(0,n-1,0);
    }

    T query(int idx){
        function<T(int,int,int)> f = [&](int tL, int tR, int tIdx){
            propogate(tL,tR,tIdx);
            if(tL==tR){
                return tree[tIdx];
            }
            int tM = tL + (tR-tL)/2;
            int ans = 0;
            if(idx<=tM){
                ans = f(tL,tM,2*tIdx+1);
            }else{
                ans = f(tM+1,tR,2*tIdx+2);
            }
            return ans;
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
    int n,m;
    cin >> n >> m;
    SegmentTree<int> st(n);
    for(int i =0;i<m;++i){
        int type;
        cin >> type;
        if(type==1){
            int l,r,x;
            cin >> l >> r >> x;
            st.update(l,r-1,x);
        }else{
            int idx;
            cin >> idx;
            cout<<st.query(idx)<<endl;
        }
    }
    return 0;
}
