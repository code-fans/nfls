#include <bits/stdc++.h>
#include <cmath>
using namespace std;
int n,d[1000],e[1000];
int dfs(int a,int b,int i,bool can){
    if(i==n&&can)
        return abs(a-b);
    else if(i==n)
        return 10000000000;
    int ans=1000000000;
    ans= min( ans , dfs(a*d[i],b+e[i],i+1,true) );
    ans= min( ans , dfs(a,b,i+1,can) );
    return ans;
}
int main(){
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>d[i]>>e[i];
    }
    cout<<dfs(1,0,0,false)<<endl;
    return 0;
}
