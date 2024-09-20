#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#define MAX_A 40
#define int long long
#define endl '\n'

class Node{
public:
    int count;
    vector<int> freq;
    Node(){
        count = 0;
        freq.assign(MAX_A + 1, 0);
    }
};

Node merge(const Node& a, const Node& b) {
    Node res;
    res.count = a.count + b.count;
    vector<int> cumulative_freq(MAX_A + 1, 0);
    cumulative_freq[0] = b.freq[0];
    for (int i = 1; i <= MAX_A; ++i) {
        cumulative_freq[i] = cumulative_freq[i - 1] + b.freq[i];
    }
    for (int i = 0; i <= MAX_A; ++i) {
        res.freq[i] = a.freq[i] + b.freq[i];
        if (i > 0) {
            res.count += a.freq[i] * cumulative_freq[i - 1];
        }
    }

    return res;
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
            if(left <= nodeLeft && nodeRight <= right){
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

    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    SegmentTree<Node> segTree(n, Node());
    for (int i = 0; i < n; ++i) {
        Node node;
        node.freq[arr[i]] = 1;
        segTree.update(i, node);
    }
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int l,r;
            cin >> l >> r;
            cout << segTree.query(l-1,r-1).count << endl;
        } else {
            int idx,val;
            cin >> idx >> val;
            Node newNode;
            newNode.freq[val] = 1;
            segTree.update(idx-1, newNode);
        }
    }
    return 0;
}

