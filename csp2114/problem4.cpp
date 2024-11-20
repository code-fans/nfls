#include <iostream>
using namespace std;
int ans=0,k;
int a[8][8];
void dfs(int x,int y,int n){
    if(x==4&&y==4){
        if(n==25-k-1)
            ans++;
        return ;
    }
    a[x][y]=1;
    if(x!=0&&a[x-1][y]==0){
        dfs(x-1,y,n+1);
    }
    if(x!=4&&a[x+1][y]==0){
        dfs(x+1,y,n+1);
    }
    if(y!=0 && a[x][y-1]==0){
        dfs(x,y-1,n+1);
    }
    if(y!=4&&a[x][y+1]==0){
        dfs(x,y+1,n+1);
    }
    a[x][y]=0;
}
int main()
{
    int x,y;
    cin>>k;
    for (int i = 0; i < k; i++){
        cin>>x>>y;
        a[x-1][y-1]=1;
    }
    if(k%2!=0||k>16){
        cout<<0<<endl;
        return 0;
    }
    dfs(0,0,0);
    cout<<ans<<endl;
    return 0;
}