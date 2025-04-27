#include <bits/stdc++.h>
using namespace std;
long long zdd(long long  a,long long b){
    while (b){
        a%=b;
        swap(a,b);
    }
    return a;
}
int main()
{
    string s;
    cin>>s;
    long long sum=0,sum1=0,z=0;
    int i,w=0,j=0,qw=0;
    for (i = 0; i < s.size(); i++){
        if(s[i]!='.'&&s[i]!='('){
            sum=sum*10+(s[i]-'0');
            z*=10;
            qw*=10;
        }else if(s[i]=='.'){
            z=1;
            qw=1;
        }else
            break;
    }
    for ( ; i < s.size(); i++){
        if(s[i]!='('&&s[i]!=')'){
            sum1=sum1*10+(s[i]-'0');
            w=w*10+9;
        }
    }
    if(z==0)
        z=1;
    long long gcdv=zdd(sum,z);
    long long fz=sum/gcdv,fm=z/gcdv,fz1=sum1,fm1=w*qw;
    if(fm1==0)
        fm1=1;
    gcdv=zdd(fm,fm1);
    long long tongfengshu=fm*fm1/gcdv;
    long long ans;
    if(fz1==0)
        ans=fz*(tongfengshu/fm);
    else
        ans=fz*(tongfengshu/fm)+fz1/(fm1/tongfengshu);
    long long ans1=tongfengshu;
    gcdv=zdd(ans,ans1);
    if(ans1/gcdv==1)
        cout<<ans/gcdv<<endl;
    else
        cout<<ans/gcdv<<'/'<<ans1/gcdv<<endl;
    return 0;
}