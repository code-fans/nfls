#include <bits/stdc++.h>
using namespace std;
long long a[10000000];
long long n,m;
long long b[101000];
int findans(int n1){
    for (long long i = 1; i <= n; i++){
        b[i]=max(a[i],b[i]);
        for (long long j = 0; j <= n1; j++){
            if(b[j]!=0){
                b[j+i]=max(b[j]+a[i],b[j+i]);
            }
        }
    }
    return b[n1];
}
int main()
{
    long long ans=0;
    cin>>n;
    long long z,y;
    for (int i = 1; i <= n; i++){
        cin>>a[i];
    }
    cin>>m;
    char a1;
    long long anst=0,s=0;
    char nans[10];
    nans[0]='a';
    nans[1]='b';
    nans[2]='c';
    for (long long i = 0; i < m; i++){
        cin>>a1;

        if(a1!=nans[s]){
            s=0;
            if(anst!=0){
                ans+=findans(anst);
                anst=0;
            }
        }
        if(a1==nans[s]){
            s++;
            if(s==3){
                anst++;
                s=0;
            }
        }
    }
    if(anst!=0)
        ans+=findans(anst);
    cout<<ans<<endl;
    return 0;
}