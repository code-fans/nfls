#include <bits/stdc++.h>
using namespace std;
char c;
int main()
{
    freopen("../csp2154/input.txt", "r", stdin);
    long long n,ans=0;
    cin>>n;
    int a[1000]={0};
    while (cin>>c){
        int a2[1000]={0};
        for (int i = 0; i < n; i++){
            int y=(i*10+(c-'0'))%n;
            a2[y]+=a[i];
        }
        a2[(c-'0')%n]++;
        for(int i=0;i<n;i++){
            a[i]=a2[i];
        }
        ans+=a[0];
    }
    cout<<ans<<endl;
    return 0;
}