#include <iostream>
using namespace std;
int a[4]= {6,8,4,2};
int main() {
    int n;
    cin>>n;
    long long ans=1;
    for(int i=2; i<=n; i++){
        ans = ans * i;
        while(ans%10==0) ans/=10;
        ans %= 10000000000l;
    }
    cout << ans%10 << endl;
    return 0;
}
//48828125