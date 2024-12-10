#include <bits/stdc++.h>
using namespace std;
long long a[100],b[100],c[100];
int main()
{
    long long ans=0;
    int n;
    cin>>n;
    long long num;
    for (int i = 0; i < n; i++){
        cin>>num;
        a[(num%46)]++;
    }
    for (int i = 0; i < n; i++){
        cin>>num;
        b[(num%46)]++;
    }
    for (int i = 0; i < n; i++){
        cin>>num;
        c[(num%46)]++;
    }
    for (int i = 0; i < 46; i++){
        int n=0;
        if(a[i]){
            n+=i;
            for(int j=0;j<46;j++){
                if(b[j]){
                    n+=j;
                    for(int k=0;k<46;k++){
                        if(c[k]&&(n+k)%46==0)
                            ans+=c[k]*b[j]*a[i];
                    }
                    n-=j;
                }
            }
            n-=i;
        }
    }
    cout<<ans<<endl;
    return 0;
}