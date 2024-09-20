#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

using namespace std;



int solve(){

}

signed main(){
    int n,q;
    cin>>n>>q;
    ordered_set st;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        st.insert(x);
    }
    while(q--){
        char type;
        cin>>type;
        if(type == '!'){
            int k,x;
            cin>>k>>x;            
        }else{
            int l,r;
            cin>>l>>r;
            cout<<st.query(l-1,r-1)<<endl;
        }
    }
    return 0;
}
