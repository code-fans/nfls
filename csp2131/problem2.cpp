#include <bits/stdc++.h>
using namespace std;
int n,ans[5500000];
int main()
{
    
    cin>>n;
    for (int i = 1; i <= n; i++){
        cin>>ans[i];
        int wi=i,f=i/2;
        while (f){
            if(ans[wi]<ans[f]){
                swap(ans[wi],ans[f]);
            }else{
                break;
            }
            wi=f;
            f/=2;
        }
    }
    for (int i = 1; i <= n; i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}