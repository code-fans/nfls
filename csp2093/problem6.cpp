#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    freopen("swap.in","r",stdin);
    freopen("swap.out","w",stdout);
    int n,a[100000], c,c1=0;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    cin>>c;
    bool j=true;
    for (int i = 1; c1 < c; i++){
        if(a[i-1]<a[i]){
            c1++;
            swap(a[i-1],a[i]);
            j=false;
        }
        if(i==n-1){
            if(j)
                break;
            i=1;
            j=true;
        }
    }
    for (int i = 0; i < n; i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
    return 0;
}