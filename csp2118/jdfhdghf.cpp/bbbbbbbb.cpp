#include <bits/stdc++.h>
using namespace std;
int a[10000000][2],ans=0;
void gethaizi(int x,int shui){
    ans=max(ans,shui);
    if(x==0)
        return ;
    gethaizi(a[x][0],shui+1);
    gethaizi(a[x][1],shui+1);
}
int main(){
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++){
        int x,y;
        cin>>x>>y;
        a[i][0]=x;
        a[i][1]=y;
    }
    gethaizi(1,0);
    cout<<ans<<endl;
    return 0;
}