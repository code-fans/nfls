#include <bits/stdc++.h>
using namespace std;
struct L {
    int x, y, s;
} st, en;
int n, m, mapp[1010][1010];
int to[4][2] = { 0, 1, 1, 0, -1, 0, 0, -1 };
char mp[1010][1010];
queue<L> q;
void bfs() {
    int i, j;
    while (!q.empty()) {
        st = q.front();
        q.pop();
        for (i = 0; i < 4; i++) {
            en.x = st.x + to[i][0];
            en.y = st.y + to[i][1];
            if (en.x >= 0 && en.x < n && en.y >= 0 && en.y < m && mapp[en.x][en.y] == -1) {
                en.s = st.s + 1;
                mapp[en.x][en.y] = en.s;
                q.push(en);
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            cout<<mapp[i][j]<<' ';
        }
        cout<<endl;
    }
}

int main() {
    int i, j;
    cin>>n>>m;
    memset(mapp, -1, sizeof(mapp));
    for (i = 0; i < n; i++) {
        cin>>mp[i];
        for (j = 0; j < m; j++) {
            if (mp[i][j] == '1') {
                st.x = i;
                st.y = j;
                st.s = 0;
                mapp[i][j] = 0;
                q.push(st);
            }
        }
    }
    bfs();
    return 0;
}