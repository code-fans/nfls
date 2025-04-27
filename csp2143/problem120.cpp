#include <bits/stdc++.h>
using namespace std;
char c[100][100];
int x, y;

int bfs() {
    queue< tuple<int,int,int, char> > q;
    q.push({1,1,1, c[1][1]});
    c[1][1]='*';
    while(! q.empty()){
        tuple<int,int,int, char> t = q.front();
        q.pop();
        int x1=get<0>(t),y1=get<1>(t),z=get<2>(t);
        if(x1==x&&y==y1)
            return z;
        char dan= get<3>(t);
        
        if (x1 != 1 && c[x1 - 1][y1] != '*' && dan!='-') {
            q.push({x1-1,y1,z+1, c[x1 - 1][y1]});
            c[x1 - 1][y1] = '*';
        }
        if (y1 != 1 && c[x1][y1 - 1] != '*' && dan != '|') {
            q.push({x1,y1-1,z+1, c[x1][y1 - 1]});
            c[x1][y1 - 1] = '*';
        }
        if (x1 != x && c[x1 + 1][y1] != '*' && dan != '-') {
            q.push({x1+1,y1,z+1, c[x1 + 1][y1]});
            c[x1 + 1][y1] = '*';
        }
        if (y1 != y && c[x1][y1 + 1] != '*' && dan != '|') {
            q.push({x1,y1+1,z+1, c[x1][y1 + 1]});
            c[x1][y1 + 1] = '*';
        }
    }
    return -1;
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