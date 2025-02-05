#include <bits/stdc++.h>
using namespace std;
int a[1000],b[1000],c[1000],f[401][401];
int main()
{
    // freopen("../csp2118/input.txt","r", stdin);
    int ma,mb,mc;
    cin>>ma>>mb>>mc;
    int ans=1e9;
  
    memset(f, 0x3f, sizeof(f));
    
    f[0][0]=0;
    for (int i = 1; i <= ma; i++)
        cin>>a[i]>>b[i]>>c[i];

    for (int i = 1; i <= ma; i++){
        for (int j = 400; j >= 0 ; j--){
            for (int k = 400; k >= 0; k--){
                if(j>=a[i]&&k>=b[i]){
                    f[j][k]=min(f[j][k],f[j-a[i]][k-b[i]]+c[i]);
                }
            }
        }
    }

    for (int i = 1; i <= 400; i++){
        for (int j = 1; j <= 400; j++){
            if(i*mc == j*mb){
                ans=min(f[i][j], ans);
            }
        }
    }
    if(ans>=1e9)
        cout<<-1<<endl;
    else
        cout<<ans<<endl;
    return 0;
}