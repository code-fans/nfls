#include<bits/stdc++.h>
using namespace std;
string a;
int c[10000000],d,e,f,g,sum,ans;
int main()
{
    cin>>d>>a>>f;
    for(int x=0;x<a.size();x++){
        if(a[x]<'A'){
            e=pow(d,a.size()-x-1);
            e*=(a[x]-'0');
            sum+=e;
        }
        else{
            e=pow(d,a.size()-1-x);
            e*=(a[x]-'A'+10);
            sum+=e;
        }
    }
        while(sum>0){
        c[g++]=sum%f;
        sum/=f;
    }
    for(int x=g-1;x>=0;x--){
        if(c[x]>=10)
            cout<<char(c[x]+'A'-10);
        else
            cout<<c[x];
    }
    return 0;
}