#include <iostream>
#include <bitset>

using namespace std;
int main()
{
    int n,ans=0;
    cin>>n;
    while (n){
        ans++;
        cout<< bitset<32>(n) << ' '<< n << '\t' << bitset<32>(n-1) << ' ' << n-1 << endl;
        n&=(n-1);
    }
    cout<<ans<<endl;
    return 0;
}