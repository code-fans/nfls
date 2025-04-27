#include <bits/stdc++.h>
using namespace std;
multiset<long long, greater<long long> > ms;
typedef pair<long long, long long> pll;
multiset<pll> ms1;
int main() {
    long long ch, co;
    cin >> ch >> co;
    long long x;
    pll y;
    for (int i = 0; i < ch; i++) {
        cin >> x;
        ms.insert(x);
    }
    for (int i = 0; i < co; i++) {
        cin >> y.first >> y.second;
        ms1.insert(y);
    }
    int ans = 0;
    auto xit = ms1.end();
    do {
        xit--; 
        auto it = ms.lower_bound(xit->second);
        if (it != ms.end() && *it >= xit->first && *it <= xit->second) {
            ans++;
            ms.erase(it);
        }
    }while( xit != ms1.begin());
    cout << ans << endl;
    return 0;
}