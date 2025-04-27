#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
long long a[1001000][5], b[1001000][2];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n, t;
    cin>>n;
    long long nishigs=0;
    a[0][0]=1;
    for (int i = 1; i <= n; i++){
        cin>>t;
        //nishigs=max(nishigs,t);
        if(i==n) nishigs = t;
        cin >>b[t][0]>>b[t][1];
    }
    for(int i=1;i<=nishigs;i++){
        for(int j=0;j<5;j++){
            if(j==4)
                a[i][j]=max(a[i-1][j],a[i-1][j-1]);
            else if(j==0)
                a[i][j]=max(a[i-1][j],a[i-1][j+1]);
            else a[i][j] =max({ a[i-1][j],a[i-1][j-1], a[i-1][j+1]});
        }
        if(a[i][b[i][0]]>0)
            a[i][b[i][0]]+=b[i][1];
    }
    cout << max({ a[nishigs][0], a[nishigs][1], a[nishigs][2], a[nishigs][3], a[nishigs][4] })-1 << endl;
    return 0;
}