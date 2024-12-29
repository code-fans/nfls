#include <bits/stdc++.h>
using namespace std;
int main() {
    long long a, c, b;
    cin >> a >> b >> c;
    long long zs=1;
    c = (c+99) % 100 + 1;
    b = b % 100;
    for (long long i = 0; i < c; i++) {
        zs *= b;
        zs %= 100;
    }
    zs = (zs+3) % 4 + 1;
    a %= 10;
    long long ans =1;
    for (long long i = 0; i < zs; i++) {
        ans *= a;
        ans %= 10;
    }
    cout << ans << endl;
    return 0;
}