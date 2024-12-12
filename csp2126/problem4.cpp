#include <bits/stdc++.h>
using namespace std;
char a[30][30];
bool vis[30][30][1500];
struct position{int x, y, key, step;};
int step[4][2] = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int main() {
    freopen("game.in", "r", stdin);
    freopen("game.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int sx = -1, sy = -1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == '@') {
                sx = i; sy = j;
                a[i][j] = '.';
            }
        }
    }
    queue<position> qu;
    qu.push({ sx, sy, 0, 0 });
    vis[sx][sy][0] = true;
    while (!qu.empty()) {
        position st = qu.front();
        qu.pop();
        for(int i=0; i<4; i++){
            int x = st.x + step[i][0];
            int y = st.y + step[i][1];
            if(a[x][y] == '^'){
                cout << st.step + 1 << endl;
                return 0;
            }
            int key = st.key;
            if(a[x][y] >= 'a' && a[x][y] <= 'z'){
                key |= 1<<(a[x][y]-97);
            }
            if( !vis[x][y][key] && ( a[x][y] == '.' ||  (a[x][y] >= 'a' && a[x][y] <= 'z') 
                || (a[x][y] >='A' && a[x][y] <='Z' && ( key & (1<<  (a[x][y]-65)))))){
                vis[x][y][key] = true;
                qu.push({ x , y, key, st.step + 1 });
            }
        }
    }
    cout << -1 << endl;
    return 0;
}