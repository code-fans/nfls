#include <bits/stdc++.h>
using namespace std;
char a[30][30];
int vis[30][30];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int sx=-1,sy=-1;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            cin>>a[i][j];
            if(a[i][j]=='@'){
                sx=i;
                sy=j;
                a[i][j]='.';
            }
        }
    }
    if(sx==-1||sy==-1){
        cout<<-1<<endl;
        return 0;
    }
    set<tuple<int ,int ,int>> foot;
    int x, y, key, step;
    queue <tuple<int ,int ,int, int>> qu;
    qu.push({sx,sy,0,0});
    foot.insert({sx,sy,0});
    while (!qu.empty()){
        tuple<int ,int ,int, int> st =qu.front();
        x = get<0>(st);
        y = get<1>(st);
        key = get<2>(st);
        step = get<3>(st);
        qu.pop();

        //上
       if(x!=0&&(a[x-1][y]=='.'||(a[x-1][y]>='a'&&a[x-1][y]<='z')||a[x-1][y]=='^'||(a[x-1][y]>='A'&&a[x-1][y]<='Z'&& key&1<<(1+a[x-1][y]-65)))){
            if(a[x-1][y]=='^'){
                cout<<step+1<<endl;
                return 0;
            }
            int newkey=key;
            if(a[x-1][y]>='a'&&a[x-1][y]<='z')
                newkey|=1<<(1+a[x-1][y]-97);
            if(foot.count({x-1,y,newkey})==0){
                qu.push({x-1,y,newkey,step+1});
                foot.insert({x-1,y,newkey});
            }
        }
       //下
        if(x!=n-1&&(a[x+1][y]=='.'||(a[x+1][y]>='a'&&a[x+1][y]<='z')||a[x+1][y]=='^'||(a[x+1][y]>='A'&&a[x+1][y]<='Z'&& key& 1<<(1+a[x+1][y]-65)))){
             if(a[x+1][y]=='^'){
                cout<<step+1<<endl;
                return 0;
            }
            int newkey=key;
            if(a[x+1][y]>='a'&&a[x+1][y]<='z')
                newkey|=1<<(1+a[x+1][y]-97);
            if(foot.count({x+1,y,newkey})==0){
                qu.push({x+1,y,newkey,step+1});
                foot.insert({x+1,y,newkey});
            }
        }
       //左
        if(y!=0&&(a[x][y-1]=='.'||(a[x][y-1]>='a'&&a[x][y-1]<='z')||a[x][y-1]=='^'||(a[x][y-1]>='A'&&a[x][y-1]<='Z'&&key&1<<(1+a[x][y-1]-65)))){
             if(a[x][y-1]=='^'){
                cout<<step+1<<endl;
                return 0;
            }
            int newkey=key;
            if(a[x][y-1]>='a'&&a[x][y-1]<='z')
                newkey|=1<<(1+a[x][y-1]-97);
            if(foot.count({x,y-1,newkey})==0){
                qu.push({x,y-1,newkey,step+1});
                foot.insert({x,y-1,newkey});
            }
        }
       //右
        if(y!=m-1&&(a[x][y+1]=='.'||(a[x][y+1]>='a'&&a[x][y+1]<='z')||a[x][y+1]=='^'||(a[x][y+1]>='A'&&a[x][y+1]<='Z'&&key&1<<(1+a[x][y+1]-65)))){
             if(a[x][y+1]=='^'){
                cout<<step+1<<endl;
                return 0;
            }
            int newkey=key;
            if(a[x][y+1]>='a'&&a[x][y+1]<='z')
                newkey|=1<<(1+a[x][y+1]-97);
            if(foot.count({x,y+1,newkey})==0){
                qu.push({x,y+1,newkey,step+1});
                foot.insert({x,y+1,newkey});
            }
        }
    }

    cout<<-1<<endl;
    return 0;
}