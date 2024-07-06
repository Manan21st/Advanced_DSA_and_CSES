#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007

using namespace std;

int solve(){

}

signed main(){
    int n,k,x;
    cin>>n>>k>>x;
    vector<int> nums(n+1);
    for(int i=0;i<=n;i++){
        if(i==k){
            nums[i]=x;
        }
        else{
            cin>>nums[i];
        }
    }
    for(int i=0;i<=n;i++){
        cout<<nums[i]<<" ";
    }
    cout<<endl;
    return 0;
}
