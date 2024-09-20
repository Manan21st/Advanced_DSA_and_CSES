#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;
int MOD;

class Node{
public:
    int mat[2][2];
    Node(){
        mat[0][0] = 1;
        mat[0][1] = 0;
        mat[1][0] = 0;
        mat[1][1] = 1;
    }
    Node(int a,int b,int c,int d){
        mat[0][0] = a;
        mat[0][1] = b;
        mat[1][0] = c;
        mat[1][1] = d;
    }
};

Node merge(Node a,Node b){
    Node res;
    res.mat[0][0] = (a.mat[0][0] * b.mat[0][0] + a.mat[0][1] * b.mat[1][0]) % MOD;
    res.mat[0][1] = (a.mat[0][0] * b.mat[0][1] + a.mat[0][1] * b.mat[1][1]) % MOD;
    res.mat[1][0] = (a.mat[1][0] * b.mat[0][0] + a.mat[1][1] * b.mat[1][0]) % MOD;
    res.mat[1][1] = (a.mat[1][0] * b.mat[0][1] + a.mat[1][1] * b.mat[1][1]) % MOD;
    return res;
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
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n,m;
    cin>>MOD>>n>>m;
    SegmentTree<Node> st(n,Node(1,0,0,1));
    for(int i=0;i<n;i++){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        st.update(i,Node(a,b,c,d));
    }
    while(m--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        Node ans = st.query(l,r);
        cout<<ans.mat[0][0]<<" "<<ans.mat[0][1]<<endl<<ans.mat[1][0]<<" "<<ans.mat[1][1]<<endl<<endl;
    }
    return 0;
}
