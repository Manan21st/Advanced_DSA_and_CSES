#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define v vector

/*
 *  Merge Sort Tree (0 based indexing)
 *  Range Query O(log^2 N)
 *  Usage:
    *   Pass initial array of type MergeSortTreeNode and neutral value to the constructor
    *   Implement the public query method
 */
struct MergeSortTreeNode {
    int* arr = NULL;
    int size = 0;

    // Constructor to create a node with a given value
    MergeSortTreeNode(int val) {
        arr = new int[1];
        arr[0] = val;
        size = 1;
    }
    // Default constructor for the neutral value
    MergeSortTreeNode() {}
};

class MergeSortTree {
    v<v<MergeSortTreeNode>> Tree;
    MergeSortTreeNode neutralValue;
    list<MergeSortTreeNode> currentIntervals;

    MergeSortTreeNode merge(MergeSortTreeNode a, MergeSortTreeNode b) {
        if (b.size == 0) return a;
        if (a.size == 0) return b;
        MergeSortTreeNode result;
        result.size = a.size + b.size;
        result.arr = new int[result.size];
        int id = result.size - 1;
        while (a.size > 0 or b.size > 0) {
            if (b.size == 0 or (a.size > 0 and a.arr[a.size - 1] >= b.arr[b.size - 1])) {
                result.arr[id--] = a.arr[a.size - 1];
                a.size--;
            } else {
                result.arr[id--] = b.arr[b.size - 1];
                b.size--;
            }
        }
        return result;
    }

    void query(int level, int idx, int treeLeft, int treeRight, int l, int r) {
        if (treeLeft > treeRight or treeRight < l or treeLeft > r or r < treeLeft or l > treeRight or level == Tree.size())
            return;
        if (l <= treeLeft and treeRight <= r) {
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

    int query(int l, int r, int k) {
        query(0, 0, 0, Tree.back().size() - 1, l, r);
        int ans = 0;
        for (auto& interval : currentIntervals) {
            ans += (lower_bound(interval.arr, interval.arr + interval.size, k) - interval.arr);
        }
        currentIntervals.clear();
        return ans;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q;
    cin >> n >> q;

    // Create the initial array of MergeSortTreeNode
    v<MergeSortTreeNode> arr;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        arr.push_back(MergeSortTreeNode(x));
    }

    // Create an instance of MergeSortTree with a neutral value
    MergeSortTreeNode neutralValue;
    MergeSortTree mst(arr, neutralValue);

    // Process the queries
    for (int i = 0; i < q; ++i) {
        int l, r, k;
        cin >> l >> r >> k;
        cout << mst.query(l, r, k) << endl;
    }

    return 0;
}
