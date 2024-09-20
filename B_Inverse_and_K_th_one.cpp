#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

class Node{
public:
    int val;
    int count;
    Node(){
        val = 0;
        count = 0;
    }
    Node(int val, int count){
        this->val = val;
        this->count = count;
    }
};

Node merge(Node a, Node b){
    if(a.val >= b.val){
        return Node(a.val,a.count+b.count);
    }
    return Node(b.val,b.count+a.count);
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
        tree[tIdx] = lazyVal[tIdx];
        lazy[tIdx] = false;
        lazyVal[tIdx] = Node();
    }

    void update(int l, int r, T x){
        function<void(int,int,int)> f = [&](int tL, int tR, int tIdx){
            propogate(tL,tR,tIdx);
            if(tL>r or tR<l){
                return;
            }
            if(l<=tL and tR<=r){
                lazy[tIdx] = true;
                lazyVal[tIdx] = Node(1-lazyVal[tIdx].val,lazyVal[tIdx].count + (lazyVal[tIdx].val ? 0:1));
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
        int type;
        cin >> type;
        if(type == 1){
            int l,r;
            cin >> l >> r;
            st.update(l,r-1,Node(1,1));
        }else{
            int k;
            cin >> k;
            k++;
            int l = 0, r = n-1;
            bool found = false;
            while(l < r){
                int m = l + (r-l)/2;
                auto temp = st.query(0,m);
                if(temp.count ==k and temp.val == 1){
                    cout << m << endl;
                    found = true;
                    break;
                }
                else if(temp.count < k){
                    l = m+1;
                }else if(temp.count > k or temp.val == 0){
                    r = m;
                }
            }
            if(!found){
                cout << l << endl;
            }
        }
    }
    return 0;
}
