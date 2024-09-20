#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long

#define v vector

struct MergeSortTreeNode {
    set<int> elements;
};

class MergeSortTree {
    v<v<MergeSortTreeNode>> Tree;
    MergeSortTreeNode neutralValue;
    list<MergeSortTreeNode> currentIntervals;

    MergeSortTreeNode merge(MergeSortTreeNode a, MergeSortTreeNode b) {
        if (b.elements.empty()) return a;
        if (a.elements.empty()) return b;
        MergeSortTreeNode result;
        set_union(a.elements.begin(), a.elements.end(), b.elements.begin(), b.elements.end(),
                inserter(result.elements, result.elements.begin()));
        return result;
    }

    void query(int level, int idx, int treeLeft, int treeRight, int l, int r) {
        if (treeLeft > treeRight || treeRight < l || treeLeft > r || r < treeLeft || l > treeRight || level == Tree.size())
            return;
        if (l <= treeLeft && treeRight <= r) {
            currentIntervals.push_back(Tree[level][idx]);
            return;
        }
        int m = (treeLeft + treeRight) / 2;
        query(level + 1, 2 * idx, treeLeft, m, l, r);
        query(level + 1, 2 * idx + 1, m + 1, treeRight, l, r);
    }

public:
    MergeSortTree(v<MergeSortTreeNode>& A, MergeSortTreeNode neutralValue) {
        this->neutralValue = neutralValue;
        int n = A.size();
        Tree.push_back(v<MergeSortTreeNode>(1, neutralValue));
        int prev = 1;
        while (prev < n) {
            Tree.push_back(v<MergeSortTreeNode>(2 * prev, neutralValue));
            prev *= 2;
        }
        int levels = Tree.size();
        for (int i = 0; i < n; i++)
            Tree[levels - 1][i] = A[i];
        for (int i = levels - 2; i >= 0; i--)
            for (int j = 0; j < (1 << i); j++)
                Tree[i][j] = merge(Tree[i + 1][2 * j], Tree[i + 1][2 * j + 1]);
    }

    int query(int l, int r) {
        query(0, 0, 0, Tree.back().size() - 1, l, r);
        set<int> result;
        for (auto& interval : currentIntervals) {
            result.insert(interval.elements.begin(), interval.elements.end());
        }
        currentIntervals.clear();
        return result.size();
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int q;
    cin >> q;

    vector<MergeSortTreeNode> A(n);
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        A[i].elements.insert(x);
    }

    MergeSortTreeNode neutralValue;
    MergeSortTree mst(A, neutralValue);
    
    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << mst.query(l-1, r-1) << endl;
    }
    return 0;
}
