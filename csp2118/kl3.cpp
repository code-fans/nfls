#include <bits/stdc++.h>
using namespace std;
int dis[110][110][110]={{{0}}};
pair <int ,int> grtt(int newx,int newy,int b){
    int y=newx+newy;
    int x=y-b;
    if(x<=0) x=0;
    if(y>b) y=b;
    return {x,y};
}
int main()
{
    int a,b,c,m;
    cin>>a>>b>>c>>m;
    queue < tuple<int ,int ,int > > q;
    q.push({a,0,0});
    dis[a][0][0]=1;
    while (!q.empty()){
        tuple<int ,int ,int > now=q.front();
        q.pop();
        int newx=get<0>(now),newy=get<1>(now),newz=get<2>(now);
        if(newx==m||newy==m||newz==m){
            cout<<"yes"<<endl;
            cout<<dis[newx][newy][newz]-1<<endl;
            return 0;
        }
        pair <int ,int > newnum;
        if (newx){
            newnum=grtt(newx,newy,b);
            if(!dis[newnum.first][newnum.second][newz]){
                dis[newnum.first][newnum.second][newz]=dis[newx][newy][newz]+1;
                q.push({newnum.first,newnum.second,newz});
            }
            newnum=grtt(newx,newz,c);
            if(!dis[newnum.first][newy][newnum.second]){
                dis[newnum.first][newy][newnum.second]=dis[newx][newy][newz]+1;
                q.push({newnum.first,newy,newnum.second});
            }
        }
        if (newy){
            newnum=grtt(newy,newx,a);
            if(!dis[newnum.second][newnum.first][newz]){
                dis[newnum.second][newnum.first][newz]=dis[newx][newy][newz]+1;
                q.push({newnum.second,newnum.first,newz});
            }
            newnum=grtt(newy,newz,c);
            if(!dis[newx][newnum.first][newnum.second]){
                dis[newx][newnum.first][newnum.second]=dis[newx][newy][newz]+1;
                q.push({newx,newnum.first,newnum.second});
            }
        }
        if (newz){
            newnum=grtt(newz,newy,b);
            if(!dis[newx][newnum.second][newnum.first]){
                dis[newx][newnum.second][newnum.first]=dis[newx][newy][newz]+1;
                q.push({newx,newnum.second,newnum.first});
            }
            newnum=grtt(newz,newx,a);
            if(!dis[newnum.second][newy][newnum.first]){
                dis[newnum.second][newy][newnum.first]=dis[newx][newy][newz]+1;
                q.push({newnum.second,newy,newnum.first});
            }
        }
    }
    cout<<"no"<<endl;
    return 0;
}