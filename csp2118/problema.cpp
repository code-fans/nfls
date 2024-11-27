#include <bits/stdc++.h>
using namespace std;
int n=0,a[500000][2],b[500000][2],h=0,and1=0,h1=0,and2=0,m,all[500000],ans[1000000][2],ansn=0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;

    for (int i = 0; i < n; i++){
        cin>>all[i];
    }

    for (int i = 0; i < n; i++){
        if(a[and1][1]==i-m) and1++;
        if(b[and2][1]==i-m) and2++;
        while(h>and1 && a[h-1][0]>=all[i])
            h--;
        while(h1>and2 && b[h1-1][0]<=all[i])
            h1--;
        a[h][1]=i;
        a[h][0]=all[i];

        h++;
        h1++;
        if(i>=m-1){
            ans[ansn][0]=a[and1][0];
            ans[ansn][1]=b[and2][0];
            ansn++;
        }
        
    }

    for (int i = 0; i < ansn; i++)
        cout<<ans[i][0]<<' ';
    cout<<endl;
    for (int i = 0; i < ansn; i++)
        cout<<ans[i][1]<<' ';
    cout<<endl;
    return 0;
}