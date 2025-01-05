#include <bits/stdc++.h>
using namespace std;
int all[1100][1100]={{0}};
int sy[1100100];
long long makeAns(int mubiao,int h){
    long long ans=0;
    int syc=0;
    int xy = all[1][0];
    for(int i=2; i<=h; i++){
        int k=1;
        while( k<= all[i][0]-mubiao+1){
            ans += all[i][k];
            k++;
            xy++;
        }
        while(  k<= all[i][0]){
            sy[syc] = all[i][k];
            syc++;
            k++;
        }
    }
    if(xy<mubiao){
        sort(sy, sy+syc);
        for(int i=0;i<mubiao-xy;i++){
            ans+=sy[i];
        }
    }
    return ans;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int c,b;
    for (int i = 0; i < m; i++){
        cin>>c>>b;
        all[c][all[c][0]+1]=b;
        all[c][0]++;
    }
    int xiyang = all[1][0], maxN=0;

    for (int i = 2; i <= n; i++){
        sort(all[i]+1, all[i]+all[i][0]+1);
        if(maxN < all[i][0])
            maxN=all[i][0];
    }
    
    long long ans=makeAns(maxN+1, n);
    if(xiyang<1) xiyang=1;
    for (int i = xiyang; i <= maxN ; i++){
        long long temp = makeAns(i, n);
        if(temp<ans){
            ans=temp;
        }
    }
    cout<<ans<<endl;
    return 0;
}