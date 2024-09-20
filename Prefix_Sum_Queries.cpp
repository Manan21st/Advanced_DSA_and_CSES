#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

class Node{
public:
    int sum;
    int prefix;
    Node(){
        prefix = 0;
        sum = 0;
    }
    Node(int sum, int prefix){
        this->sum = sum;
        this->prefix = prefix;
    }
};

Node merge(Node a, Node b){
    Node c;
    c.sum = a.sum + b.sum;
    c.prefix = max(a.prefix, a.sum+b.prefix);
    return c;
}

template<typename T>
class SegmentTree{
public:
    int n;
    T identity;
    vector<T> tree;
    SegmentTree(int n, T identity){
        this->n = n;
        this->identity = identity;
        tree.resize(4*n+1);
    }
    void update(int qIdx, T val){
        function<void(int,int,int)> f = [&](int tL, int tR, int tIdx){
            if(tL==tR){
                tree[tIdx] = val;
                return;
            }
            int tM = (tL + tR)/2;
            if(tL<= qIdx and qIdx<=tM){
                f(tL, tM, 2*tIdx+1);
            }
            else{
                f(tM+1, tR, 2*tIdx+2);
            }
            tree[tIdx] = merge(tree[2*tIdx+1],tree[2*tIdx+2]);
        };
        f(0, n-1, 0);
    }

    T query(int l, int r){
        function<T(int,int,int)> f = [&](int tL, int tR, int tIdx){
            if(l<=tL && tR<=r){
                return tree[tIdx];
            }
            if(tL>r || tR<l){
                return identity;
            }
            int tM = (tL + tR)/2;
            return merge(f(tL, tM, 2*tIdx+1),f(tM+1, tR, 2*tIdx+2));
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
        SegmentTree<Node> st(n, Node());
        for(int i=0;i<n;++i){
            int x;
            cin >> x;
            st.update(i, Node(x,x));
        }
        for(int i=0;i<q;++i){
            int type;
            cin >> type;
            if(type==1){
                int idx, val;
                cin >> idx >> val;
                st.update(idx-1, Node(val,val));
            }
            else{
                int l, r;
                cin >> l >> r;
                cout << max(st.query(l-1, r-1).prefix,0ll) << endl;
            }
        }
    }
    return 0;
}