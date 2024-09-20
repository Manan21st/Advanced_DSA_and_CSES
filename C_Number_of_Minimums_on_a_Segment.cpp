#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

class Node{
public:
    int val;
    int cnt;
    Node() : val(LLONG_MAX), cnt(0) {}

    Node(int val,int cnt){
        this->val = val;
        this->cnt = cnt;
    }
};

Node merge(Node a, Node b){
    if(a.val<b.val){
        return a;
    }else if(a.val>b.val){
        return b;
    }else{
        return Node(a.val,a.cnt+b.cnt);
    }
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
    return 0;
}

signed main(){
    int n,q;
    cin>>n>>q;
    SegmentTree<Node> st(n,Node(LLONG_MAX,0));
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        st.update(i,Node(x,1));
    }
    while(q--){
        int type;
        cin>>type;
        if(type==2){
            int l,r;
            cin>>l>>r;
            Node ans = st.query(l,r-1);
            cout<<ans.val<<" "<<ans.cnt<<endl;
        }else{
            int idx,val;
            cin>>idx>>val;
            st.update(idx,Node(val,1));
        }
    }
    return 0;
}

