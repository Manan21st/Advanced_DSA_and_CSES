#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define mod 1000000007
#define endl '\n'

using namespace std;

int getMedian(vector<int>& sorted,int val){
    int n =sorted.size();
    int l = 0;
    int r = n-1;
    int remove =-1;
    vector<int> temp = sorted;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(temp[mid]==val){
            remove = mid;
            break;
        }
        else if(temp[mid]<val){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    temp.erase(temp.begin()+remove);
    if(temp.size()%2==0){
        return temp[(temp.size()-1)/2];
    }
    
    return temp[temp.size()/2];
    
}

int solve(vector<int>& arr,vector<int>& bin,int k){
    int n = arr.size();
    int ans=0;
    vector<int> sorted = arr;
    sort(sorted.begin(),sorted.end());
    for(int i=0;i<n;++i){
        int med = getMedian(sorted,arr[i]);
        int add =0;
        if(bin[i]==1){
            add = k;
        }
        ans = max(ans,arr[i]+add+med);
    }
    return ans;
}

signed main(){
    //This belongs to Manan Agrawal
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test;
    cin>>test;
    for(int t =0;t<test;++t){
        int n,k;
        cin>>n>>k;
        vector<int> arr(n);
        vector<int> bin(n);
        for(int i=0;i<n;++i){
            cin>>arr[i];
        }
        for(int i=0;i<n;++i){
            cin>>bin[i];
        }
        cout << solve(arr,bin,k) << endl;
    }
    return 0;
}
