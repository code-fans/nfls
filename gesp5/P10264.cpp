#include <iostream>
#include <utility>
using namespace std;

long long gcd(long long a, long long b){
    if(b==0) return a;
    return gcd(b, a%b);
}

int main(){
	ios::sync_with_stdio(false);
	long long l, v1, v2, t;
    cin >> l >> v1 >> v2 >> t;
    if(v1>v2){
        swap(v1, v2);
    }
    if(v2==0){
        cout << 0 << endl;
        return 0;
    }
    if(v1==0){
        cout << (v2*t / l +1) / 2  << endl;
        return 0;
    }
    long long sum= v2+ v1, diff= v2- v1;
    long long ans= (sum*t+ l)/ (2* l)+(diff*t+ l)/(2* l);
    long long d= __gcd(v1, v2);
    if( (v1/d % 2) != (v2 /d % 2))
        ans -=(d*t+ l)/ (2*l);

    cout << ans << endl;
    return 0;
}