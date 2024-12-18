#include <bits/stdc++.h>
using namespace std;
char a[16][16] = { { 0 } };
int sx, sy;
int dfs(int x, int y, int c) {
    if (c!=0&& x == sx && y == sy) {
        if(c>2)
            return c;
        return -1;
    }

    int ans = -1000;
    a[x][y] = '#';
    if (a[x][y + 1] == '.' || (x == sx && y + 1 == sy))
        ans = max(ans, dfs(x, y + 1, c + 1));
    if (a[x][y - 1] == '.' || (x == sx && y - 1 == sy))
        ans = max(ans, dfs(x, y - 1, c + 1));
    if (a[x + 1][y] == '.' || (x + 1 == sx && y == sy))
        ans = max(ans, dfs(x + 1, y, c + 1));
    if (a[x - 1][y] == '.' || (x - 1 == sx && y == sy))
        ans = max(ans, dfs(x - 1, y, c + 1));
    a[x][y] = '.';
    return ans;
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) cin >> a[i][j];
    int ans = -1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '.') {
                a[i][j] = '#';
                sx = i;
                sy = j;
                ans = max(ans, dfs(i, j, 0));
                a[i][j] = '.';
            }
        }
    cout << ans << endl;
    return 0;
}
