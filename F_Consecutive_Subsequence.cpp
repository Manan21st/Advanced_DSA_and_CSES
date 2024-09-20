#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> &A) {

    map<int, int> mp;
    int last_elem = -1;
    for(int elem : A)
    {
        if(mp.count(elem - 1))
        {
            mp[elem] = 1 + mp[elem - 1];
        }
        else
        {
            mp[elem]  = 1;
        }
        if(mp[elem] > mp[last_elem])
        {
            last_elem = elem;
        }
    }
    
    vector<int> result;
    for(int i = A.size() - 1; i >= 0; --i)
    {
        if(A[i] == last_elem)
        {
            result.push_back(i);
            last_elem--;
        }
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}


int main()
{
    int n;
    cin >> n;
    vector<int> A(n);
    for(int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    vector<int> result = solve(A);
    cout  << result.size() << endl;
    for(int i = 0; i < result.size(); i++)
    {
        cout << result[i] + 1 << " ";
    }
}