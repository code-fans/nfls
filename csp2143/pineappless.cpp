#include <bits/stdc++.h>
using namespace std;
long long a[1100000], ans=0,b[1100000];
void msort(int l,int r)
{
    if(l==r-1) 
        return;
    long long mid=(l+r)/2;
    msort(l,mid);
    msort(mid,r);
    int i=l,h=mid,j=l;
    while (i<mid&&h<r){
        if(a[i]<a[h]){
            b[j]=a[h];
            ans += mid-i;
            h++;
        } else {
            b[j]=a[i];
            i++;
        }
        j++;
    }
    while (i<mid||h<r){
        if(h<r){
            b[j]=a[h];
            h++;
        }else{
            b[j]=a[i];
            i++;
        }
        j++;
    }
    for (i = l; i < r; i++) {
        a[i]=b[i];
        b[i]=0;
    }
}
int main()
{
    long long n;
    cin>>n;
    long long r;
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    msort(0,n);
    cout<<ans<<endl;
    return 0;
}