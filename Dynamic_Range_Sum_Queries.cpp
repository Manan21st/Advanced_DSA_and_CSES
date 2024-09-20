#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

class SegmentTree{
public:
    int N;
    int identity=0;
    vector<int> tree;

    SegmentTree(int n,int identity){
        N = n;
        this->identity = identity;
        tree.assign(4*N,identity);
    }

    int merge(int a, int b){
        return a+b;
    }

    void update(int qIdx, int val){
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

    int query(int l, int r){
        function<int(int,int,int)> func = [&](int tIdx, int tLeft, int tRight){
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
    return 0;
}

signed main(){
    int n,q;
    cin >> n >> q;
    SegmentTree st(n+1,0);
    for(int i =1;i<=n;i++){
        int temp;
        cin >> temp;
        st.update(i,temp);
    }

    for(int i =0;i<q;i++){
        int type;
        cin >> type; 
        if(type==1){
            int idx,val;
            cin >> idx >> val;
            st.update(idx,val);
        }else{
            int l,r;
            cin >> l >> r;
            cout << st.query(l,r) << endl;
        }
    }

    return 0;
}
