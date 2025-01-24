#include <bits/stdc++.h>
using namespace std;
int n;
char a[1000][1000];
int dx[4]={1,-1,0,0},dy[4]={0,0,-1,1};
int findans(int chang,char f[],int size,int x,int y,int hasy){
    if(a[x][y]==')'){
        size--;
        hasy=1;
    }else{
        if(hasy==1)
            return 0;
        f[size]='(';
        size++;
    }
    if(size==0&&chang!=1)
        return chang;
    char mu=a[x][y];
    a[x][y]='X';
    int ans=0;
    
    for (int i = 0; i < 4; i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<0||nx>=n||ny<0||ny>=n||a[nx][ny]=='X')
            continue;
        ans=max(ans,findans(chang+1,f,size,nx,ny,hasy));
    }
    a[x][y]=mu;
    return ans;
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin>>a[i][j];
    char f[100000];
    cout<<findans(1,f,0,0,0,0)<<endl;
    return 0;
}