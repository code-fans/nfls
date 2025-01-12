#include <bits/stdc++.h>
using namespace std;
int n,a[3000],l,r;
int main()
{
    int m;
    cin>>m>>n;
    memset(a,0x3f,sizeof(int)*3000);
    for (int i = 0; i < m; i++){
        cin>>l>>r;
        for(int j=n;j>0;j--){
            if(j<=r){
                a[j]=min(a[j],l);
            } else  if(a[j-r]>0){
                    a[j] = min( a[j-r] + l,  a[j]); 
            }
        }
    }
    if(a[n]!=a[n+1])
        cout<<a[n]<<endl;
    else
        cout<<"no solution"<<endl;
    return 0;
}