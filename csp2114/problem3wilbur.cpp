#include <bits/stdc++.h>
using namespace std;
int f[100];
int dfs(int a,int b,int c,int d,int aa,int bb,int cc,int dd,int ff){
    if(ff==12)
        return max({aa,bb,cc,dd})-min({aa,bb,cc,dd});
    int ans=1000000;
    if(a<3)
        ans = min(dfs(a+1,b,c,d,aa+f[ff],bb,cc,dd,ff+1),ans);
    if(b<3)
        ans = min(dfs(a,b+1,c,d,aa,bb+f[ff],cc,dd,ff+1),ans);
    if(c<3)
        ans = min(dfs(a,b,c+1,d,aa,bb,cc+f[ff],dd,ff+1),ans);
    if(d<3)
        ans = min(dfs(a,b,c,d+1,aa,bb,cc,dd+f[ff],ff+1),ans);
    return ans;
}
int main()
{
    
    for (int i = 0; i < 12; i++){
        cin>>f[i];
    }
    cout<<dfs(0,0,0,0,0,0,0,0,0)<<endl;
    return 0;
}
/*

*/