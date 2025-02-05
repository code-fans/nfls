#include <bits/stdc++.h>
using namespace std;
int a[10000];
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        a[m]++;
    }
    long long ans = 0;
    ans += a[4];
    ans += a[3];
    a[1] -= a[3];
    if (a[1] <= 0)
        a[1] = 0;
    ans += a[2] / 2;
    if (a[2] % 2) {
        a[1] -= 2;
        ans++;
        if (a[1] <= 0)
            a[1] = 0;
    }
    ans += (a[1] + 3) / 4;
    cout << ans << endl;
    return 0;
}