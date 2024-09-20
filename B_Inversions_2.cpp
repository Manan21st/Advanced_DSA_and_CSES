#include <iostream>
#include <bits/stdc++.h>
#define mod 1000000007

using namespace std;

#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
template <typename T>
class OrderedSet {
private:
    tree< T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> st;
public:
    int countElementsLessThanX(T x) {
        return st.order_of_key(x);
    }

    int countElementsAtleastX(T x) {
        return st.size() - countElementsLessThanX(x);
    }

    int getKthElement(int k) {
        return *st.find_by_order(k);
    }
    
    void insert(T x) {
        st.insert(x);
    }
    
    void erase(T x) {
        st.erase(x);
    }
};


int solve(){
    return 0;
}

signed main(){
    int n;
    cin >> n;
    OrderedSet<int> st;
    for(int i=1;i<=n;++i){
        st.insert(i);
    }
    vector<int> a(n);
    for(int i=0;i<n;++i){
        cin >> a[i];
    }
    vector<int> ans(n);
    for(int i =n-1;i>=0;--i){
        ans[i] = st.getKthElement(i-a[i]);
        st.erase(ans[i]);
    }
    for(int i=0;i<n;++i){
        cout << ans[i] << " ";
    }
    return 0;
}

