#include <iostream>
#include <cmath>
using namespace std;

int n,m,a[100100];

void go(int b, int c){
    if(c==0 || b>= n-1)
        return;
    int maxN = -1000000, maxP;
    for(int i=b; i<n && i< c+b+1; i++ ){
        if(maxN < a[i]){
            maxN = a[i];
            maxP = i;
        }
    }
    for(int i=maxP; i>b;i--){
        a[i] = a[i-1];
    }
    a[b] = maxN;
    go(b+1, c-maxP+b);
}

int main()
{
    //freopen("swap.in","r",stdin);
    //freopen("swap.out","w",stdout);
    
    cin>>n;
    for (int i = 0; i < n; i++)
        cin>>a[i];
    cin>>m;
    go(0, m);
    for (int i = 0; i < n; i++)
        cout<<a[i]<<' ';
    cout<<endl;
    return 0;
}