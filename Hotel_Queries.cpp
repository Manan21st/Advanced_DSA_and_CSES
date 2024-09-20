#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

int merge(int a, int b){
    return max(a,b);
}

template<typename T>
class SegmentTree{
public:
    vector<T> tree;
    int n;
    T identity;
    SegmentTree(int n, T identity){
        this->n = n;
        this->identity = identity;
        tree.resize(4*n,identity);
    }
    void update(int qIdx, T val){
        function<void(int,int,int)> f = [&](int tIdx,int tLeft, int tRight){
            if(tLeft == tRight){
                tree[tIdx] = val;
                return;
            }
            int tMid = tLeft + (tRight-tLeft)/2;
            if(tLeft<=qIdx and qIdx<=tMid){
                f(2*tIdx+1,tLeft,tMid);
            }else{
                f(2*tIdx+2,tMid+1,tRight);
            }
            tree[tIdx] = merge(tree[2*tIdx+1],tree[2*tIdx+2]);
        };
        f(0,0,n-1);
    }
    int query(T val){
        function<int(int,int,int)> f = [&](int tIdx, int tLeft, int tRight){
            if(tLeft==tRight){
                tree[tIdx] -= val;
                return tLeft;
            }
            int tMid = tLeft + (tRight-tLeft)/2;
            int res;
            if(tree[2*tIdx+1]>=val){
                res = f(2*tIdx+1,tLeft,tMid);
            }else{
                res = f(2*tIdx+2,tMid+1,tRight);
            }
            tree[tIdx] = merge(tree[2*tIdx+1],tree[2*tIdx+2]);
            return res;
        };
        return f(0,0,n-1);
    }
};

int solve(){
    return 0;
}

signed main(){
    int n, m;
    cin>>n>>m;
    SegmentTree<int> st(n,0);
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        st.update(i,x);
    }
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        if(x>st.tree[0]){
            cout<< 0 << " ";
        }else{
            cout<<st.query(x)+1<< " ";
        }
    }   
    cout << endl;

    return 0;
}
