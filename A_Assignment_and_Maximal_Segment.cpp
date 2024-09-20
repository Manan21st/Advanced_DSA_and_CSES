#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

class Node{
public:
    int sum;
    int prefix;
    int suffix;
    int ans;

    Node(){
        sum = 0;
        prefix = 0;
        suffix = 0;
        ans = 0;
    }

    Node(int x,int length){
        sum = x*length;
        prefix = ans = suffix = max(x*length,x);
    }

    Node(int sum, int prefix, int suffix, int ans){
        this->sum = sum;
        this->prefix = prefix;
        this->suffix = suffix;
        this->ans = ans;
    }
};

Node merge(Node a, Node b){
    Node res;
    res.sum = a.sum + b.sum;
    res.prefix = max(a.prefix, a.sum + b.prefix);
    res.suffix = max(b.suffix, b.sum + a.suffix);
    res.ans = max({a.ans, b.ans, a.suffix + b.prefix});
    return res;
}

template<typename T>
class SegmentTree{
public:
    int n;
    T identity;
    vector<T> tree;
    vector<bool> lazy;
    vector<T> lazyVal;
    SegmentTree(int n, T identity){
        this->n = n;
        this->identity = identity;
        tree.resize(4*n,identity);
        lazy.resize(4*n,false);
        lazyVal.resize(4*n,identity);
    }

    void propogate(int tL, int tR, int tIdx){
        if(!lazy[tIdx]){
            return;
        }
        if(tL<tR){
            lazyVal[2*tIdx+1] = lazyVal[tIdx];
            lazyVal[2*tIdx+2] = lazyVal[tIdx];
            lazy[2*tIdx+1] = true;
            lazy[2*tIdx+2] = true; 
        }
        tree[tIdx] = Node(lazyVal[tIdx].sum, tR-tL+1);
        lazy[tIdx] = false;
        lazyVal[tIdx] = Node();
    }

    // void update(int idx, int val){
    //     int l = idx, r = idx;
    //     function<void(int, int, int)> f = [&](int tid, int tl, int tr){

    //         // no overlap
    //         if(tl > r or tr < l){ 
    //             return;
    //         }
    //         // complete overlap
    //         if(l <= tl and tr <= r)
    //         {
    //             tree[tid] = val;
    //             return;
    //         }
    //         int tm = (tl + tr) / 2;
    //         f(2*tid+1,tl, tm);
    //         f(2*tid+2,tm+1, tr);
    //         tree[tid] = merge(tree[2*tid+1],tree[2*tid+2]);
    //     };
    //     f(0, 0, n-1);
    // }

    void update(int l, int r, T x){
        function<void(int,int,int)> f = [&](int tL, int tR, int tIdx){
            propogate(tL,tR,tIdx);
            if(tL>r or tR<l){
                return;
            }
            if(l<=tL and tR<=r){
                lazy[tIdx] = true;
                lazyVal[tIdx] = x;
                propogate(tL,tR,tIdx);
                return;
            }
            int tM = tL + (tR-tL)/2;
            f(tL,tM,2*tIdx+1);
            f(tM+1,tR,2*tIdx+2);
            tree[tIdx] = merge(tree[2*tIdx+1],tree[2*tIdx+2]);
        };
        f(0,n-1,0);
    }

    T query(int l, int r){
        function<T(int,int,int)> f = [&](int tL, int tR, int tIdx){
            propogate(tL,tR,tIdx);
            if(tL>r or tR<l){
                return identity;
            }

            if(l<=tL and tR<=r){
                return tree[tIdx];
            }

            int tM = tL + (tR-tL)/2;
            auto left = f(tL,tM,2*tIdx+1);
            auto right = f(tM+1,tR,2*tIdx+2);
            return merge(left,right);
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
    SegmentTree<Node> st(n,Node());
    for(int i =0;i<m;++i){
        int l,r,val;
        cin >> l >> r >> val;
        st.update(l,r-1,Node(val,val,val,val));
        cout <<max(0LL,st.query(0,n-1).ans)<< endl;
    }
    return 0;
}
