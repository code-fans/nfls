#include <bits/stdc++.h>
using namespace std;
long long ans=0,n,a[1000000]={0};
double mcshu[1000000]={0};
int main()
{
    cin>>n;
    cin>>a[0];
    mcshu[0] = 1;
    for (int i = 1; i <= n; i++){
        cin>>a[i];

        mcshu[i]=(mcshu[i-1]-a[i-1])*2;
    }

    long long shang= 0;
    for (int i = n; i >= 0; i--){
        if( (shang+1) / 2 + a[i] > mcshu[i]+0.1){
            cout<<-1<<endl;
            return 0;
        }
        shang = ( shang+a[i] < mcshu[i]+0.1) ? shang+a[i] : mcshu[i]+0.1;
        ans += shang;
    }
    cout<<ans<<endl;
    return 0;
}