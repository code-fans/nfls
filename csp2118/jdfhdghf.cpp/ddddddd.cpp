#include <bits/stdc++.h>
using namespace std;
int main(){
    long long n;
    cin>>n;
    if(n<=2) {
        cout << 1 << endl; 
        return 0;
    }
    long long f1=1, f2=1, fn;
    for(long long i=3; i<=n; i++){
        fn = f1 + f2;
        fn %= 1000000007;
        f1 = f2;
        f2 = fn;
    }
    cout << fn<< endl;
    return 0;
}