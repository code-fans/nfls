#include <bits/stdc++.h>
using namespace std;

void jcw(long long n){
    long long ans=1;
    for(long long i=2; i<=n; i++){
        ans *= i;
        while(ans%10==0) ans/=10;
        ans %= 1000000000000l;
        cout << ans << endl;
    }
}

int main(){
    jcw(100);
    return 0;
}