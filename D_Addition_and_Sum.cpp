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
    vector<T> lazyVal;
    SegmentTree(int n){
        this->n = n;
        tree.resize(4*n,0LL);
        lazy.resize(4*n,false);
        lazyVal.resize(4*n,0LL);
    }

    void propogate(int tL, int tR, int tIdx){
        if(!lazy[tIdx]){
            return;
        }
        if(tL<tR){
            lazyVal[2*tIdx+1] += lazyVal[tIdx];
            lazyVal[2*tIdx+2] += lazyVal[tIdx];
            lazy[2*tIdx+1] = true;
            lazy[2*tIdx+2] = true;
        }
        tree[tIdx] += lazyVal[tIdx]*(tR-tL+1);
        lazy[tIdx] = false;
        lazyVal[tIdx] = 0;
    }

    void update(int l, int r, T x){
        function<void(int,int,int)> f = [&](int tL, int tR, int tIdx){
            propogate(tL,tR,tIdx);
            if(tL>r or tR<l){
                return;
            }
            if(l<=tL and tR<=r){
                lazy[tIdx] = true;
                lazyVal[tIdx] += x;
                propogate(tL,tR,tIdx);
                return;
            }
            int tM = tL + (tR-tL)/2;
            f(tL,tM,2*tIdx+1);
            f(tM+1,tR,2*tIdx+2);
            tree[tIdx] = (tree[2*tIdx+1]+tree[2*tIdx+2]);
        };
        f(0,n-1,0);
    }

    T query(int l, int r){
        function<T(int,int,int)> f = [&](int tL, int tR, int tIdx){
            propogate(tL,tR,tIdx);
            if(tL>r or tR<l){
                return 0LL;
            }

            if(l<=tL and tR<=r){
                return tree[tIdx];
            }

            int tM = tL + (tR-tL)/2;
            int left = f(tL,tM,2*tIdx+1);
            int right = f(tM+1,tR,2*tIdx+2);
            return (left+right);
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
    SegmentTree<int> st(n+1);
    for(int i =0;i<m;++i){
        int type;
        cin >> type;
        if(type==1){
            int l,r,x;
            cin >> l >> r >> x;
            st.update(l,r-1,x);
        }else{
            int l,r;
            cin >> l >> r;
            cout<<st.query(l,r-1)<<endl;
        }
    }
    return 0;
}
