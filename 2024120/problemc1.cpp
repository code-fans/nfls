
#include <bits/stdc++.h>
using namespace std;
long long a[1100][1100]={{0}};
long long ans[101000]={0};
int main(){
    int n,x,y,x1,y1;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>x>>y>>x1>>y1;
        a[x+1][y+1]++;
        a[x+1][y1+1]--;
        a[x1+1][y+1]--;
        a[x1+1][y1+1]++;
    }
    for (int i = 1; i <= 1010; i++){
        for (int j = 1; j <= 1010; j++){
            a[i][j]+=a[i][j-1]+a[i-1][j]-a[i-1][j-1];
            ans[a[i][j]]++;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}