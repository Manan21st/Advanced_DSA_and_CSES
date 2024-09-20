#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

int merge(int a, int b){
    return a+b;
}

template<typename T>
class SegmentTree{
public:
    int N;
    T identity;
    vector<T> tree;

    SegmentTree(int n,T identity){
        N = n;
        this->identity = identity;
        tree.assign(4*N,identity);
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
            tree[tIdx] = merge(tree[2*tIdx+1],tree[2*tIdx+2]);
        };
        func(0,0,N-1);
    }

    T query(int l, int r){
        function<T(int,int,int)> func = [&](int tIdx, int tLeft, int tRight){
            // no overlap
            if(r<tLeft or l>tRight){
                return identity;
            }

            // complete overlap
            if(l<=tLeft and tRight<=r){
                return tree[tIdx];
            }

            // partial overlap
            int tMid = tLeft + (tRight-tLeft)/2;
            return merge(func(2*tIdx+1,tLeft,tMid),func(2*tIdx+2,tMid+1,tRight));
        };
        return func(0,0,N-1);
    }   
};

int solve(){

}

signed main(){
    int n,m;
    cin >> n >> m;
    SegmentTree<int> st(n+1,0LL);
    for(int i =0;i<n;i++){
        int x;
        cin >> x;
        st.update(i,x);
    }

    for(int i=0;i<m;i++){
        int type;
        cin>>type;
        if(type==1){
            int l,r,v;
            cin >> l >> r >> v;
            st.update(l,st.query(l,l)+v);
            st.update(r,st.query(r,r)-v);
        }else{
            int idx;
            cin >> idx;
            cout << st.query(0,idx) << endl;
        }
    }
    return 0;
}
