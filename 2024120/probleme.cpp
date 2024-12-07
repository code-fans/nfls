#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a[1000];
    long long ans=0;
    for (int i = 0; i < 7; i++){
        cin>>a[i];
    }
    ans = a[0] + a[1] +a[3] +a[4] ;
    long long r = a[0]%2 + a[3]%2 + a[4]%2;
    if(r == 1 || r == 2){
        ans--;
    }
    if(r == 2){
        if(a[0] < 1 || a[3] < 1 || a[4] < 1){
            ans--;
        }
    }
    cout<<ans<<endl;
    return 0;
}