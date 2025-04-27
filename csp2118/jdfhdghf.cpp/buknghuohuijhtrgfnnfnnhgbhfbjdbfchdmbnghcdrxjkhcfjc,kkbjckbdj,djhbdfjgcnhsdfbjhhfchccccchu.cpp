#include <bits/stdc++.h>
using namespace std;
long long bx[4]={1,-1,0,0};
long long by[4]={0,0,-1,1};
long long cnt[9010][9010]={{0}};
int main()
{
    queue <pair<long long ,long long > > q;
    long long n,m;
    cin>>n>>m;
    for (long long i = 1; i <= n; i++){
        for (long long j = 1; j <= m; j++){
            char a1;
            cin>>a1;
            if(a1=='X'){
                q.push({i,j});
                cnt[i][j]=3;
            }
        }
    }
    long long ans=0;
    while (!q.empty()){
        ans++;
        pair<long long ,long long> num=q.front();
        q.pop();
        long long x=num.first,y=num.second,num1=0;
        for (long long i = 0; i < 4; i++){
            cnt[x+bx[i]][y+by[i]]++;
            if(cnt[x+bx[i]][y+by[i]]==2&&x+bx[i]>0&&x+bx[i]<=n&&y+by[i]>0&&y+by[i]<=m){
                q.push({x+bx[i],y+by[i]});
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}