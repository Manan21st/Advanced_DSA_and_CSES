#include <iostream>
using namespace std;

bool isTrue(int a1, int a2, int b1, int b2) {
    return (a1 > b1 && a2 > b2);
}

int solve(int a,int b, int c,int d) {
    int count = 0;
    if (isTrue(a, b, c, d)) count++;
    if (isTrue(a, b, d, c)) count++;
    if (isTrue(b, a, c, d)) count++;
    if (isTrue(b, a, d, c)) count++;
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << solve(a,b,c,d) << endl;
    }
    
    return 0;
}
