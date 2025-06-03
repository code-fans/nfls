#include <bits/stdc++.h>
using namespace std;
int a[1000000][2],n;
int main()
{
    cin>>n;
    for(int i=0;i<(1<<n);i++){
        cin>>a[i][0];
        a[i][1]=i;
    }
    for(int i=n;i>=2;i--){
        int size=0,ji=0;
        for(int j=0;j<=(1<<i);j+=2){
            if(a[j][0]<a[j+1][0])
                ji=1;
            a[size][0]=a[j+ji][0];
            a[size][1]=a[j+ji][1];
            ji=0;
            size++;
        }
    }
    if(a[0][0]<a[1][0])
        cout<<a[0][1]+1<<endl;
    else
        cout<<a[1][1]+1<<endl;
    return 0;
}