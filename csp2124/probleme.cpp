#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
long long ans[101000], c[100000][2], and1 = 0, h1 = 0;
int main() {
    long long W, N, l, r, v;
    cin >> W >> N;
    memset(ans, -1, sizeof(ans));
    ans[0] = 0;
    long long p = 0;

    for (int i = 0; i < N; i++) {
        cin >> l >> r >> v;
        p += r;
        long long beginP = min(p, W);
        long long m = r - l + 1;
        and1 = 0;
        c[0][1] = beginP - l;
        c[0][0] = ans[beginP - l];
        h1 = 1;
        for (int j = beginP - l; j >= 0; j--) {
            if (c[and1][1] == j + m)
                and1++;
            while (h1 > and1 && c[h1 - 1][0] <= ans[j]) h1--;
            c[h1][1] = j;
            c[h1][0] = ans[j];
            h1++;
            if (c[and1][0] != -1 && ans[j + r] < c[and1][0] + v) {
                ans[j + r] = c[and1][0] + v;
            }
        }
        for (int j = r; j >= l; j--) {
            if (c[and1][1] > j - l)
                and1++;
            if (and1 < h1 && c[and1][0] != -1 && ans[j] < c[and1][0] + v) {
                ans[j] = c[and1][0] + v;
            }
        }
    }
    cout << ans[W] << endl;
    return 0;
}