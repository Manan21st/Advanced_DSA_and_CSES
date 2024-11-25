#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'
 
using namespace std;
 
 
template<typename T>
class SegmentTree{
public:
    int N;
    T identity;
    vector<T> tree;
    vector<T> lazyadd,lazyset;
    vector<bool> lazy;
 
    SegmentTree(int n,T identity){
        N = n;
        this->identity = identity;
        tree.assign(4*N,identity);
        lazyadd.assign(4*N,0);
        lazyset.assign(4*N,identity);
        lazy.assign(4*N,false);
    }
 
    T merge(T a, T b){
        return a+b;
    }
 
    void propagateSet(int tIdx, int tL, int tR){
        if(!lazy[tIdx]){
            return;
        }
        if(tL<tR){
            lazy[2*tIdx+1] = true;
            lazy[2*tIdx+2] = true;
            lazyset[2*tIdx+1] = lazyset[tIdx];
            lazyset[2*tIdx+2] = lazyset[tIdx];
            lazyadd[2*tIdx+1] = 0;
            lazyadd[2*tIdx+2] = 0;
        }
        tree[tIdx] = lazyset[tIdx]*(tR-tL+1);
        lazy[tIdx] = false;
    }
 
    void propagateAdd(int tIdx, int tL, int tR){
        if(lazyadd[tIdx]==0){
            return;
        }
        if(tL<tR){
            lazyadd[2*tIdx+1] += lazyadd[tIdx];
            lazyadd[2*tIdx+2] += lazyadd[tIdx];
        }
        tree[tIdx] += lazyadd[tIdx]*(tR-tL+1);
        lazyadd[tIdx] = 0;
    }
 
    void update(int l, int r, T val){
        function<void(int,int,int)> func = [&](int tIdx,int tL, int tR){
            propagateSet(tIdx, tL, tR); 
            propagateAdd(tIdx, tL, tR);
            if(r<tL or l>tR){
                return;
            }
 
            if(l<=tL and tR<=r){
                lazy[tIdx] = true;
                lazyset[tIdx] = val;
                lazyadd[tIdx] = 0;
                propagateSet(tIdx,tL,tR);
                return;
            }
 
            int tMid = tL + (tR-tL)/2;
            func(2*tIdx+1,tL,tMid);    
            func(2*tIdx+2,tMid+1,tR);
            tree[tIdx] = merge(tree[2*tIdx+1],tree[2*tIdx+2]);
        };
        func(0,0,N-1);
    }
 
    void add(int l, int r, T val){
        function<void(int,int,int)> func = [&](int tIdx,int tL, int tR){
            propagateSet(tIdx, tL, tR); 
            propagateAdd(tIdx, tL, tR);
            if(r<tL or l>tR){
                return;
            }
 
            if(l<=tL and tR<=r){
                lazyadd[tIdx] += val;
                propagateAdd(tIdx,tL,tR);
                return;
            }
 
            int tMid = tL + (tR-tL)/2;
            func(2*tIdx+1,tL,tMid);    
            func(2*tIdx+2,tMid+1,tR);
            tree[tIdx] = merge(tree[2*tIdx+1],tree[2*tIdx+2]);
        };
        func(0,0,N-1);
    }
 
    T query(int l, int r){
        function<T(int,int,int)> func = [&](int tIdx, int tL, int tR){
            propagateSet(tIdx, tL, tR);
            propagateAdd(tIdx, tL, tR);
            // no overlap
            if(r<tL or l>tR){
                return identity;
            }
 
            // complete overlap
            if(l<=tL and tR<=r){
                return tree[tIdx];
            }
 
            // partial overlap
            int tMid = tL + (tR-tL)/2;
            return merge(func(2*tIdx+1,tL,tMid),func(2*tIdx+2,tMid+1,tR));
        };
        return func(0,0,N-1);
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
        SegmentTree<int> st(n,0);
        for(int i=0;i<n;++i){
            int x;
            cin >> x;
            st.update(i,i,x);
        }
        for(int i=0;i<q;++i){
            int type,l,r;
            cin >> type >> l >> r;
            --l,--r;
            if(type==1){
                int x;
                cin >> x;
                st.add(l,r,x);
            }else if(type==2){
                int x;
                cin >> x;
                st.update(l,r,x);
            }else{
                cout << st.query(l,r) << endl;
            }
        }
    }
    return 0;
}
