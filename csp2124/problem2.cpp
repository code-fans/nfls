#include <bits/stdc++.h>
using namespace std;
long long dfs(long long a,long long b){
    while (a!=0&&b!=0){
        a%=b;
        swap(a,b);
    }
    return max(a,b);
}
int main()
{
    long long a,b,c;
    cin>>a>>b>>c;
    int n=dfs(dfs(a,b),c);
    cout<<a/n+b/n+c/n-3<<endl;
    return 0;
}