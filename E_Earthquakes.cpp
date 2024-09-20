#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

class Node{
public:
    int idx;
    int val;
    Node(){
        idx = -1;
        val = LLONG_MAX;
    }
    Node(int idx, int val){
        this->idx = idx;
        this->val = val;
    }
};

Node merge(Node a, Node b) {
    if(a.val < b.val) return a;
    return b;
}

template<typename T>
class SegmentTree{
public:
    int n;
    vector<T> tree;
    T identity;
    SegmentTree(int size, T identity) {
        n = size;
        this->identity = identity;
        tree.assign(4 * n, identity);
    }

    void build(T val){
        function<void(int,int,int)> f = [&](int node,int nodeLeft, int nodeRight){
            if(nodeLeft == nodeRight){
                tree[node] = val;
                return;
            }
            int mid = (nodeLeft + nodeRight) / 2;
            f(2 * node + 1, nodeLeft, mid);
            f(2 * node + 2, mid + 1, nodeRight);
            tree[node] = merge(tree[2 * node + 1],tree[2 * node + 2]);
        };
        f(0, 0, n - 1);
    }

    void update(int idx, T val) {
        function<void(int,int,int)> f = [&](int node, int nodeLeft, int nodeRight){
            if(nodeLeft == nodeRight){
                tree[node] = val;
                return;
            }
            int mid = (nodeLeft + nodeRight) / 2;
            if(idx <= mid){
                f(2 * node + 1, nodeLeft, mid);
            }
            else{
                f(2 * node + 2, mid + 1, nodeRight);
            }
            tree[node] = merge(tree[2 * node + 1],tree[2 * node + 2]);
        };
        f(0, 0, n - 1);
    }

    T query(int left, int right) {
        function<T(int,int,int)> f = [&](int node, int nodeLeft, int nodeRight){
            if(left > nodeRight || right < nodeLeft){
                return identity;
            }
            if(left <= nodeLeft && nodeRight<=right){
                return tree[node];
            }
            int mid = (nodeLeft + nodeRight) / 2;
            return merge(f(2 * node + 1, nodeLeft, mid),f(2 * node + 2, mid + 1, nodeRight));
        };
        return f(0, 0, n - 1);
    }
};


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;
    SegmentTree<Node> segTree(n, Node());
    while (q--) {
        int type;
        cin >> type;
        if (type == 2) {
            int l,r,p;
            cin >> l >> r >> p;
            int ans=0;
            while(true){
                Node val = segTree.query(l,r-1);
                if(val.val>p){
                    break;
                }
                ans++;
                segTree.update(val.idx,Node(val.idx,LLONG_MAX));
            }
            cout << ans << endl;
        } else {
            Node curr;
            cin >> curr.idx >> curr.val;
            segTree.update(curr.idx, curr);
        }
    }
    return 0;
}

