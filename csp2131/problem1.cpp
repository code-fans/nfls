#include <bits/stdc++.h>
using namespace std;
long long s, p;
int main() {
    cin >> s >> p;
    cout << s * p << endl;
    long long l=1,r=s/2;
    while (l<=r){
        long long mid=(l+r)/2;
        
        if(mid*(s-mid)==p){
            cout<<"Yes"<<endl;
            return 0;
        }
        if(mid*(s-mid)>p)
            r=mid-1;
        else 
            l=mid+1;
    }
    cout<<"No"<<endl;
    return 0;
}
//1000000000000 999999999999