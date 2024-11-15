#include <bits/stdc++.h>
using namespace std;
int catalan1(int ca){
    long long num[100];
    num[0] = num[1] = 1;
    num[2] = 2;
    for (int n = 3; n <= ca; n++){
        num[n]  =0;
        for(int i=0;i<n; i++){
            num[n] += num[i]*num[n-i-1];
        }
    }
    return num[ca];
}
int catalan2(int n){
    if(n<=1)
        return 1;
    return catalan2(n-1)*(4*n-2)/(n+1);
}
int catalan3(int n){
    long long num=1;
    for(int i=0;i<n;i++){
        num = num * (2*n-i) / (i+1);
    }
    return num/(n+1);
}

int catalan4(int n){
    long long num=1;
    for(int i=0;i<n-1;i++){
        num = num * (2*n-i) / (i+1);
    }
    long long num2 = num * (n+1) / n;
    return num2-num;
}

int catalan5(int n){
    long long a[10000]={0};
    a[0]=1;
    for (int i=1;i<=n;i++){
        for (int j = i; j < n+1; j++){
            a[j]+=a[j-1];
        }
    }
    return a[n];
}
int main()
{
    int n;
    cin>>n;
    cout<<catalan4(n)<<endl<<catalan2(n)<<endl<<catalan3(n)<<endl<<catalan4(n)<<endl<<catalan5(n)<<endl;
    return 0;
}