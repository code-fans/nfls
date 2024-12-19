#include <bits/stdc++.h>
using namespace std;
long long s, p;
int main() {
    cin >> s >> p;
    long long l=1, r=sqrt(p)+0.5;
    while (l<=r){ //l < r-1
        long long mid=(l+r)/2;
        long long shang = p/mid, ys = p%mid;
        if(mid+shang==s && ys==0){
            cout<<"Yes"<<endl;
            return 0;
        }
        if(shang+mid>=s)
            l=mid+1;
        else
            r=mid-1;
    }
    cout<<"No"<<endl;
    return 0;
}
//1000000000000 999999999999
//2000000 1000000000000