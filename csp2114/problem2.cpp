#include <bits/stdc++.h>
using namespace std;
int dfs(int aa,int b,int c,int aoa,int aob,int a[],int d,int n){
    if(d==n&&(c==0||abs(aa-b)>1||aa==0||b==0))
        return 100000000;
    else if(d==n)
        return abs(aoa-aob);
    int ans=1000000;
    int kk=min(dfs(aa+1,b,c,aoa+a[d],aob,a,d+1,n),min(dfs(aa,b+1,c,aoa,aob+a[d],a,d+1,n),dfs(aa,b,c+1,aoa,aob,a,d+1,n)));
    if(ans>kk){
        ans=kk;
    }
    return ans;
}
int main()
{
    int n,k;
    cin>>n;
    int a[100000];
    for (int i = 0; i < n; i++){
        cin>>k;
        for (int j = 0; j < k; j++){
            cin>>a[j];
        }
        cout<<dfs(0,0,0,0,0,a,0,k)<<endl;
    }
    return 0;
}