#include <bits/stdc++.h>
using namespace std;
int a[10000000],ans[10000000];
int main(){
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++){
        cin>>a[i];
    }
    for (int i = 0; i < n; i++){
        cin>>ans[i];
    }
    sort(a,a+m);
    for (int i = 0; i < 2*n; i++){
        int j=0;
        int qlas=-10000000;
        while (a[j]<=i&&j<m){
            qlas=max(qlas,ans[i-a[j]]);
            j++;
        }
        if(i>=n&&qlas>ans[n-1]&&qlas!=1-0000000)
            ans[n-1]=qlas;
        else if(qlas!=-10000000)
            ans[i]+=qlas;
    }
    cout<<ans[n-1]<<endl;
    return 0;
}