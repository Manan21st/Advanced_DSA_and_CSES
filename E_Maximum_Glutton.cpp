#include <iostream>
#include <bits/stdc++.h>
#define int long long

using namespace std;

struct dish {
    int sweetness;
    int saltiness;
};

bool comparedishes(const dish& a, const dish& b) {
    return (a.sweetness + a.saltiness) < (b.sweetness + b.saltiness);
}

signed main() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<dish> dishes(n);
    for (int i = 0; i < n; ++i) {
        cin >> dishes[i].sweetness >> dishes[i].saltiness;
    }

    sort(dishes.begin(), dishes.end(), comparedishes);

    int totalsweetness = 0;
    int totalsaltiness = 0;
    int maxdishes = 0;

    for (const auto& d : dishes) {
        if (totalsweetness <= x && totalsaltiness <= y) {
            totalsweetness += d.sweetness;
            totalsaltiness += d.saltiness;
            ++maxdishes;
        } else {
            break;
        }
    }

    cout << maxdishes << endl;
    return 0;
}
