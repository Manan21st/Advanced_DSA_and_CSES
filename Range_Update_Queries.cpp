#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int merge(int a, int b){
    return a+b;
}

template<typename T>
class SegmentTree{
public:
    int n;
    vector<T> tree;
    vector<bool> lazy;
    vector<T> lazyVal;
    T identity;
    SegmentTree(int n, T identity){
        this->n = n;
        this->identity = identity;
        tree.resize(4*n+1);
        lazy.resize(4*n+1);
        lazyVal.resize(4*n+1);
    }
    void propogate(int l, int r, int idx){
        if(l!=r){
            lazy[2*idx+1] = true;
            lazy[2*idx+2] = true;
            lazyVal[2*idx+1] += lazyVal[idx];
            lazyVal[2*idx+2] += lazyVal[idx];
        }
        tree[idx] += (r-l+1)*lazyVal[idx];
        lazy[idx] = false;
        lazyVal[idx] = 0;
    }

    void update(int l, int r, T val){
        function<void(int,int,int)> f = [&](int tL, int tR, int tIdx){
            propogate(tL, tR, tIdx);
            if(l<=tL && tR<=r){
                lazy[tIdx] = true;
                lazyVal[tIdx] += val;
                propogate(tL, tR, tIdx);
                return;
            }
            if(tL>r || tR<l){
                return;
            }
            int tM = (tL + tR)/2;
            f(tL, tM, 2*tIdx+1);
            f(tM+1, tR, 2*tIdx+2);
            tree[tIdx] = merge(tree[2*tIdx+1],tree[2*tIdx+2]);
        };
        f(0, n-1, 0);
    }

    T query(int idx){
        int l = idx;
        int r = idx;
        function<T(int,int,int)> f = [&](int tL, int tR, int tIdx){
            propogate(tL, tR, tIdx);
            if(l>tR or r<tL){
                return identity;
            }
            if(l<=tL and tR<=r){
                return tree[tIdx];
            }
            int tM = (tL + tR)/2;
            return merge(f(tL, tM, 2*tIdx+1), f(tM+1, tR, 2*tIdx+2));
        };
        return f(0, n-1, 0);
    }
};

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test=1;
    // cin>>test;
    for(int t =0;t<test;++t){
        int n,q;
        cin >> n >> q;
        SegmentTree<int> st(n, 0);
        for(int i=0;i<n;++i){
            int val;
            cin >> val;
            st.update(i, i, val);
        }
        for(int i=0;i<q;++i){
            int type;
            cin >> type;
            if(type==1){
                int l,r,val;
                cin >> l >> r >> val;
                st.update(l-1, r-1, val);
            }else{
                int idx;
                cin >> idx;
                cout << st.query(idx-1) << endl;
            }
        }
    }
    return 0;
}