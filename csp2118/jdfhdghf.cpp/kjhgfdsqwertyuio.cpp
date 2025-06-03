#include <bits/stdc++.h>
using namespace std;
int a[1001010]={0};
int main()
{
    int n;
    cin>>n;
    for (int i = 1; i <= 75; i++)
        for(int j = 1;j < i; j++)
            a[i*i-j*j]=1;
    int i=1;
    while(n)
        n-=a[i++];
    cout<<i-1<<endl;
    return 0;
}