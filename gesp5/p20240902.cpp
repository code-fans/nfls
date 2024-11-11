#include <bits/stdc++.h>
using namespace std;
#define MAXN 100100

int prm[MAXN]={0},size1=0,prm1[MAXN]{0};
void pr(){
    for(long long i=2; i<MAXN; i++){
        if(prm[i]==0){
            prm1[size1]=i;
            size1++;
        }
        for (long long j = 0; j < size1 && prm1[j]*i < MAXN; j++){
            prm[prm1[j]*i]=1;
            if( i%prm1[j]==0)
                break;
        }
    }
}

int main()
{
    prm[0]=1;
    prm[1]=1;
    pr();
    long long n,m,ms=0;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>m;
        long long mn=1;
        for(int j=1;m>0;j++){
            if(prm[m]==0){
                m=0;
                cout<<j<<endl;
                break;
            }
            m-=mn;
            if(m==0){
                cout<<j<<endl;
                break;
            }
            mn*=2;
        }
        if(m!=0)
            cout<<-1<<endl;
    }
    return 0;
}