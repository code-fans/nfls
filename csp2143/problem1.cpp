#include <bits/stdc++.h>
using namespace std;
multiset<long long> st;
int main() {
    long long q, x, k, op;
    cin >> q;
    while (q--) {
        cin >> op;
        if (op == 1) {
            cin >> x;
            st.insert(x);
        } else if (op == 2) {
            cin >> x >> k;
            auto it = st.upper_bound(x);
            for (int i = 1; i <= k; i++) {
                if (it == st.begin()) {
                    cout << -1 << endl;
                    break;
                }
                it--;
                if (i == k) {
                    cout << *it << endl;
                }
            }
        } else {
            cin >> x >> k;
            auto it = st.lower_bound(x);
            for (int i = 2; i <= k; i++) {
                if (it == st.end()) {
                    break;
                }
                it++;
            }
            if (it == st.end()) {
                cout << -1 << endl;
            } else {
                cout << *it << endl;
            }
        }
    }
}