#include <iostream>
using namespace std;
long long n,anssun=0,ans[100000];
int main()
{
    freopen("formula.in","r",stdin);
    freopen("formula.out","w",stdout);
    cin>>n;
    for (int i = 1; i < n; i++){
        int a=i,c=0;
        while (a){
            c+=a%10;
            a/=10;
        }
        if(n==c+i){
            ans[anssun]=i;
            anssun++;
        }
    }
    cout<<anssun<<endl;
    for (int i = 0; i < anssun; i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}