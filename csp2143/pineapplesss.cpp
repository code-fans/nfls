#include <bits/stdc++.h>
using namespace std;
unsigned long long z=10000000000;

unsigned long long zdd(unsigned long long  a, unsigned long long b){
    while (b){
        a%=b;
        swap(a,b);
    }
    return a;
}
int main()
{
    string s;
    unsigned long long b=0,z=0;
    cin>>s;
    int ssize=s.size();
    for (int i = 0; i < ssize; i++){
        if(s[i]!='.'){
            b = b * 10 + s[i]-'0';
            z*=10;
        }else{
            z=1;
        }
    }
    if(z==0)
        z=1;
    unsigned long long gcdv=zdd(b,z);
    if(z==gcdv)
        cout<<b/gcdv<<endl;
    else
        cout<< b/gcdv <<'/'<< z/gcdv <<endl;
    return 0;
}