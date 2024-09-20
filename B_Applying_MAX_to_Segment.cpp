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
    SegmentTree(int n){
        this->n = n;
        tree.resize(4*n);
    }
    void update(int l, int r, T x){
        function<void(int,int,int)> f = [&](int tL, int tR, int tIdx){
            if(tL>r or tR<l){
                return;
            }
            if(tL>=l and tR<=r){
                tree[tIdx] = max(x,tree[tIdx]);
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
            if(tL==tR){
                return tree[tIdx];
            }
            int tM = tL + (tR-tL)/2;
            int ans = tree[tIdx];
            if(idx<=tM){
                ans = max(ans,f(tL,tM,2*tIdx+1));
            }else{
                ans = max(ans,f(tM+1,tR,2*tIdx+2));
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
