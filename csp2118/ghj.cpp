#include <bits/stdc++.h>                                 
using namespace std;                                     
int a[1000][1000],k,f[1000][1000];                       
int n,m;                                                 
int main()
{
    char a1;
    cin>>n>>m>>k;
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            cin>>a1;
            a[i][j]=a1-48;
            f[i][j]+=a[i][j];
            f[i][j]=f[i][j]+f[i-1][j]+f[i][j-1]-f[i-1][j-1];
        }
    }
    int ans=1000000000;
    for (int i = 1; i <= n; i++){
        for(int j = 1;j <= m;j++){
            for (int w = i; w <= n; w++){
                for (int l = j; l <= m; l++){
                    if(f[w][l]-f[i-1][l]-f[w][j-1]+f[i-1][j-1]>=k){
                        ans=min(ans,(w-i+1)*(l-j+1));
                    }
                }
            }
        }
    }
    if(ans==1000000000)
        cout<<0<<endl;
    else
        cout<<ans<<endl;
    return 0;
    
}