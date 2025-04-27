#include <bits/stdc++.h>
using namespace std;
bool dfs(int n, int k, int s) {
    if (n < k)
        return false;
    if (k == 1) {
        return n > s;
    }
    long long minn = 1;
    for (int i = 0; i < k; i++) {
        minn *= (s + 1 + i);
        if (minn > n) {
            return false;
        }
    }
    for (int i = s + 1; i * i <= n; i++) {
        if (n % i == 0) {
            if (dfs(n / i, k - 1, i)) {
                return true;
            }
        }
    }
    if (n > s + 1 && dfs(1, k - 1, n)) {
        return true;
    }
    return false;
}
int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, k;
        cin >> n >> k;
        if (k > 12) {
            cout << "NIE\n";
            continue;
        }
        if (dfs(n, k, 0)) {
            cout << "TAK\n";
        } else {
            cout << "NIE\n";
        }
    }
    return 0;
}