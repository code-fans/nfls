#include <bits/stdc++.h>
using namespace std;
int n;
int a[21][21];
map<int, int> cnt[21];
long long ans = 0;
void dfs1(int x, int y, int s) {
    if (x == n/2+1) {
        cnt[y][s]++;
        return;
    }
	s ^= a[x][y];
    dfs1(x + 1, y, s);
	if(y+1<=n)
    	dfs1(x, y + 1, s);
}

void dfs2(int x, int y, int s) {
    if (x == n/2) {
        ans += cnt[y][s];
        return;
    }
    s ^= a[x][y];
    dfs2(x - 1, y, s);
	if(y-1>=1)
    	dfs2(x, y - 1, s);
}

int main() {
	freopen("../csp2118/input.txt", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    dfs1(1, 1, 0);
    dfs2(n, n, 0);
    cout << ans << endl;
}