#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int ap[26] = { 0,  2,  3,  5,  7,  11, 13, 17, 19, 23, 29, 31, 37,
               41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97 };

int p[26], m = 0;

ll n, u;

ll f[30000000], tot = 0;
ll ans = 0;

void dfs1(int dep, ll mul) {
    if (dep == m / 2 + 1) {
        f[++tot] = mul;
        return;
    }
    while (mul <= n) {
        dfs1(dep + 1, mul);
        mul *= p[dep];
    }
}

void dfs2(int dep, ll mul) {
    if (dep == m + 1) {
        ans += upper_bound(f + 1, f + 1 + tot, n / mul) - f - 1;
        return;
    }
    while (mul <= n) {
        dfs2(dep + 1, mul);
        mul *= p[dep];
    }
}

int main() {
    cin >> n >> u;
    for (int i = 1; i <= 25; i++) {
        if (ap[i] <= u)
            p[++m] = ap[i];
    }
    random_shuffle(p + 1, p + 1 + m);
    dfs1(1, 1);
    sort(f + 1, f + 1 + tot);
    dfs2(m / 2 + 1, 1);
    cout << ans << endl;
}