#include <iostream>
using namespace std;
const int mod = 1e9 + 7;
int n, q;
long long x[60], y[60], z[60], w[60];
long long ans = 1;
int main() {
    cin >> n >> q;
    for (int i = 1; i <= q; i++) {
        cin >> x[i] >> y[i] >> z[i] >> w[i];
    }
    for (int i = 0; i < 60; i++) {
        long long tmp = 0;
        for (int st = 0; st < 1 << n; st++) {
            bool flag = true;
            for (int j = 1; j <= q; j++) {
                int xi = (st >> (x[j] - 1)) & 1;
                int yi = (st >> (y[j] - 1)) & 1;
                int zi = (st >> (z[j] - 1)) & 1;
                int wi = (w[j] >> i) & 1;
                if (!((xi | yi | zi) == wi)) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                tmp++;
            }
        }
        ans = (ans * tmp) % mod;
    }
    cout << ans;
    return 0;
}