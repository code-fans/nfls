#include <bits/stdc++.h>
using namespace std;
int n,a[10000000][2]={{0}};
int z[1000000]={0};
int main()
{
    cin>>n;
    for (int i = 1; i < n; i++){
        int x;
        cin>>x;
        if(a[x][0]==0)
            a[x][0]=i+1;
        else
            a[x][1]=i+1;
    }
    string zuangtai;
    cin>>zuangtai;
    int m;
    cin>>m;
    int x;
    
    for (int i = 0; i < m; i++){
        cin>>x;
        z[x]++;
    }
    for(int i=1;i<=n;i++){
        z[a[i][0]]+=z[i];
        z[a[i][1]]+=z[i];
    }
    for(int i=1;i<=n;i++){
        if(z[i]%2)
            cout<<((zuangtai[i-1]-'0')+1)%2;
        else
            cout<<zuangtai[i-1]-'0';
    }
    return 0;
}