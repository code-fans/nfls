#include <bits/stdc++.h>
using namespace std;
int dfs(int a,int b,int c){
    if(c>a*b/2) c = a*b-c;
    if(c==0) return 0;
    int d=1e9;
    int l=c/b;
    if(l>0)
        d=min(d,b*b+dfs(a-l,b,c%b));
    if(l+1<a&& c%b!=0)
        d=min(d,b*b+dfs(l+1,b,c));    
    l=c/a;
    if(l>0)
        d=min(d,a*a+dfs(a,b-l,c%a));
    if(l+1<b&& c%a!=0)
        d=min(d,a*a+dfs(a,l+1,c));    
    return d;
}

int main()
{
    int n;
    cin>>n;
    int a,b,c;
    for (int i = 0; i < n; i++){
        cin>>a>>b>>c;
        cout<<dfs(a,b,c)<<endl;
    }
    return 0;
}