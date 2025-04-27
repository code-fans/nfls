#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[1000];
ll GCD (ll a, ll b){
    while(b!=0){
        ll c = a%b;
        a = b;
        b = c;
    }
    return a;
}
int main()
{
   
    cout<< GCD(232,990)<<endl;
    return 0;
}