#include <iostream>
#include <bits/stdc++.h>
#define int long long

using namespace std;

int findKthClosestDistance(const vector<int>& a, int b, int k) {
    int n = a.size();
    
    int pos = lower_bound(a.begin(), a.end(), b)-a.begin();
    
    priority_queue<int> maxHeap;
    
    int left = pos-1; 
    int right = pos;    

    while (left >= 0 || right < n) {
        if (left < 0) {
            maxHeap.push(abs(a[right] - b));
            if (maxHeap.size() > k){
                maxHeap.pop();
            }
            ++right;
        } else if (right >= n) {
            maxHeap.push(abs(a[left] - b));
            if (maxHeap.size() > k){ 
                maxHeap.pop();
            }
            --left;
        } else {
            maxHeap.push(abs(a[left] - b));
            if (maxHeap.size() > k){ 
                maxHeap.pop();
            }
            maxHeap.push(abs(a[right] - b));
            if (maxHeap.size() > k){ 
                maxHeap.pop();
            }
            --left;
            ++right;
        }
    }
    return maxHeap.top();
}

signed main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    
    sort(a.begin(), a.end());

    while (q--) {
        int b, k;
        cin >> b >> k;
        cout << findKthClosestDistance(a, b, k) << endl;
    }
    
    return 0;
}
