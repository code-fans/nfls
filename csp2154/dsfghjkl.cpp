#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin>>n;
    int t=0;
    for (long long i = 2; i*i <= n; i++){
        int num=0;
        while (n%i==0){
            n/=i;
            num++;
        }
        if(t&&num!=0)
            cout<<" * ";
        if(num>=2){
            cout<<i<<'^'<<num;
            t++;
        }else if(num!=0){
            cout<<i;
            t++;
        }
    }
    if(t)
        cout<<" * ";
    cout<<n;
    t++;
    return 0;
}