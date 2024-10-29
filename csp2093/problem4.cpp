#include <bits/stdc++.h>
using namespace std;
int n,m, matrix[1010][1010];
int visit[1010][1010] = {0};
bool dfscheck(int mx){ // 广度搜索
    memset(visit, 0, sizeof(visit));
    queue<pair<int, int>> qu;
    qu.push({0,0});
    visit[0][0] = 1;
    while(!qu.empty()){
        pair<int, int> p = qu.front();
        qu.pop();
        if(p.first < n-1 && visit[p.first+1][p.second] == 0 && matrix[p.first+1][p.second] <= mx){
            if(p.first==n-2){
                return true;
            }
            visit[p.first+1][p.second] = 1;
            qu.push({p.first+1, p.second});
        }
        if(p.first > 0 && visit[p.first-1][p.second] == 0 && matrix[p.first-1][p.second] <= mx){
            visit[p.first-1][p.second] = 1;
            qu.push({p.first-1, p.second});
        }
        if(p.second > 0 && visit[p.first][p.second-1] == 0 && matrix[p.first][p.second-1] <= mx){
            visit[p.first][p.second-1] = 1;
            qu.push({p.first, p.second-1});
        }
        if(p.second < m-1 && visit[p.first][p.second+1] == 0 && matrix[p.first][p.second+1] <= mx){
            visit[p.first][p.second+1] = 1;
            qu.push({p.first, p.second+1});
        }
    }
    return false;
}
int main(){
    cin >> n >> m;
    int l=1e9,x=0;
    for(int i=0;i<n;i++){
        for(int j=0; j<m; j++){
            cin >> matrix[i][j];
            if(i!=0 && i!=n-1){
                if(l> matrix[i][j]){
                    l = matrix[i][j];
                }
                if(x < matrix[i][j]){
                    x = matrix[i][j];
                }
            }
        }
    }
    l--;
    while(l+1<x){
        int mid = (l+x) / 2;
        if(dfscheck(mid)){
            x = mid;
        } else {
            l = mid;
        }
    }
    cout << x << endl;
    return 0;
}
