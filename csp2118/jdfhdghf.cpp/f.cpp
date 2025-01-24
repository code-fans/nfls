#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000][1000],g=0,b[1000][1000];
long long dx[4]={1,-1,0,0};
long long dy[4]={0,0,-1,1};
int numofone=0;
int vis[1000][1000];
void findans(int x,int y,int num)
{
    vis[x][y]=1;
    numofone+=b[x][y];
    for (int i = 0; i < 4; i++){
        int nx=x+dx[i],ny=y+dy[i];
        if(nx<=0||nx>n||ny<=0||ny>m||vis[nx][ny]||abs(a[nx][ny]-a[x][y])>num)
            continue;
        findans(nx,ny,num);
    }
    return ;
}
bool isans(int num){
    memset(vis,0,sizeof(vis));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(b[i][j]){
                numofone=0;
                findans(i,j,num);
                return numofone==g;
            }
        }
    }
    return false;
}
int main()
{   
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>a[i][j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>b[i][j];
            g+=b[i][j];
        }
    }
    long long l=0,r=1000000000,ans=0;
    while (l<=r){
        long long mid=(l+r)/2;
        if(isans(mid)){
            ans=mid;
            r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans<<endl;
    return 0;
}