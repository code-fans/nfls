#include <bits/stdc++.h>
using namespace std;
long long dis[1010][1010]={{0}},dis2[1010][1010]={{0}},n,m;
char cmap[1010][1010]={{0}};
int main()
{
    long long x,y,x1,y1,x2,y2;
    cin>>n>>m;
    queue < pair <long long ,long long > > q;
    for (long long i = 1; i <= n; i++){
        for (long long j = 1; j <= m; j++){
            cin>>cmap[i][j];
            if(cmap[i][j]=='*'){
                q.push({i,j});
                dis[i][j]=1;
            }
        }
    }
    long long bx[4]={1,-1,0,0};
    long long by[4]={0,0,-1,1};
    while (!q.empty()){
        pair<long long ,long long > num=q.front();
        q.pop();
        long long nowx=num.first,nowy=num.second;
        for (long long i = 0; i < 4; i++){
            long long newx=nowx-bx[i],newy=nowy-by[i];
            if(newx>0&&newy>0&&newx<=n&&newy<=m&&!dis[newx][newy]&&cmap[newx][newy]!='X'&&cmap[newx][newy]!='D'){
                dis[newx][newy]=dis[nowx][nowy]+1;
                q.push({newx,newy});
            }
        }
    }
    for (long long i = 1; i <= n; i++){
        for (long long j = 1; j <= m; j++){
            if (cmap[i][j]=='S'){
                q.push({i,j});
                dis2[i][j]=1;
            }
        }
    }
    
    while (!q.empty()){
        pair<long long ,long long > num=q.front();
        q.pop();
        long long nowx=num.first,nowy=num.second;
        for (long long i = 0; i < 4; i++){
            long long newx=nowx-bx[i],newy=nowy-by[i];
            if(cmap[newx][newy]=='D'){
                    cout<<dis2[nowx][nowy]<<endl;
                    return 0;
            }

            if(newx>0&&newy>0&&newx<=n&&newy<=m&&!dis2[newx][newy]&&dis[newx][newy]>dis2[nowx][nowy]+1&&cmap[newx][newy]!='X'){
                dis2[newx][newy]=dis2[nowx][nowy]+1;
                q.push({newx,newy});
                
            }
        }
    }
    cout<<"KAKTUS"<<endl;
    return 0;
}