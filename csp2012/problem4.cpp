#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,k,a,b[120]={0},ans=0;
    cin>>n>>k;
    for (int i = 0; i < n; i++){
        cin>>a;
        b[i%k]+=a&1;
    }
    int t=n/k, halft = t/2;
    for (int i = 0; i < k; i++){
        ans+= b[i]>halft?t-b[i]:b[i];
    }
    cout<<ans<<endl;
    return 0;
}
