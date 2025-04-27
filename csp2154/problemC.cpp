#include <iostream>
#include <cstring>
#include <queue>
#include <utility>
#include <sstream>
using namespace std;
char c[100][100];
int x, y;
int bfs() {
    int vis[100][100]={{0}};
    queue< pair<int,int> > q;
    q.push({1,1});
    vis[x][y]=-1;
    vis[1][1]=1;
    while (!q.empty()){
        pair<int ,int> p =  q.front();
        q.pop();
        int mx=p.first,my=p.second;
        if(mx==x&&my==y)
            break;
        if (mx!=1&&vis[mx-1][my]<=0&&c[mx][my]!='-'&&c[mx-1][my]!='*') {
            q.push({mx-1,my});
            vis[mx-1][my]=vis[mx][my]+1;
        }
        if (my!=1&&vis[mx][my-1]<=0&&c[mx][my]!='|'&&c[mx][my-1]!='*') {
            q.push({mx,my-1});
            vis[mx][my-1]=vis[mx][my]+1;
        }
        if (mx!=x&&vis[mx+1][my]<=0&&c[mx][my]!='-'&&c[mx+1][my]!='*') {
            q.push({mx+1,my});
            vis[mx+1][my]=vis[mx][my]+1;
        }
        if (my!=y&&vis[mx][my+1]<=0&&c[mx][my]!='|'&&c[mx][my+1]!='*') {
            q.push({mx,my+1});
            vis[mx][my+1]=vis[mx][my]+1;
        }
    }
    return vis[x][y];
}
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        for (int j = 1; j <= x; j++)
            for (int v = 1; v <= y; v++)
                cin >> c[j][v];
        cout<< bfs() <<endl;
    }
    return 0;
}