#include <iostream>
using namespace std;
int main()
{
    int n,ans=0;
    cin>>n;
    while (n){
        ans++;
        n&=(n-1);
        cout<< n << endl;
    }
    cout<<ans<<endl;
    return 0;
}