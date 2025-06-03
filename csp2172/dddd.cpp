#include <bits/stdc++.h>
using namespace std;
int n;
int a[1000005];
bool u[1000005],f=true;
int gcd(int a, int b) {
    while (b != 0) {
        int t = b;
        b = a % b;
        a = t;
    }
    return a;
}
int main(){
    cin>>n;
    int g=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        g=gcd(g,a[i]);
    }
    if(g!=1)
        cout<<"not coprime"<<endl;
    else{
        for(int i=1;i<=n;i++){
            int x=a[i];
            for(int j=2;j*j<=x;j++){
                if(x%j==0){
                    if(u[j]){
                        f=false;
                        break;
                    }
                    u[j]=true;
                    while(x%j==0)
                        x/=j;
                }
            }
            if(x!=1){
                if(u[x])
                    f=false;
                else
                    u[x]=true;
            }
            if(!f)
                break;
        }
        if(f)
            cout<<"pairwise coprime"<<endl;
        else
            cout<<"setwise coprime"<<endl;
    }

    return 0;
}