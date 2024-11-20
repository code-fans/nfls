#include <bits/stdc++.h>
using namespace std;
int main()
{
    int ans=0;
    char a;
    char n[220000];
    //freopen("../csp2110/input.in","r",stdin);
    while (cin>>a){
        n[ans]=a;
        if(ans>0&& n[ans-1]=='S'&&a=='T')
            ans-=2;
        ans++;
    }
    cout<<ans<<endl;
    return 0;
}