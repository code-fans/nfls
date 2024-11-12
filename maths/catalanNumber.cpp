#include <iostream>
#include <bitset>
using namespace std;

long long cn[10000];
long long catalan1(int n){
    cn[0] = cn[1] = 1;

    for(int i=2; i<=n; i++){
        cn[i] = 0;
        for(int j=0; j<i; j++){
            cn[i] += cn[j] * cn[i-j-1];
        }
    }
    return cn[n];
}

long long catalan2(int n){
    cn[0] = cn[1] = 1;
    for(int i=2; i<=n; i++){
        cn[i] = cn[i-1] * (4*i - 2) / (i+1);
    }
    return cn[n];
}

long long catalan3(int n){
    long long ct = 1;
    for(int i=0;i<n;i++){
        // ct *= (2*n-i) / (i+1); 改成这样行不行
        ct = ct * (2*n-i) / (i+1);
    }
    return ct / (n+1);
}

long long catalan4(int n){
    long long ct = 1;
    for(int i=0;i<n;i++){
        // ct *= (2*n-i) / (i+1); 改成这样行不行
        ct = ct * (2*n-i) / (i+1);
    }
    long long ctn1 = ct * n / (n+1);
    return ct - ctn1;
}

long long ct2d[1000][1000];
long long catalan5(int n){
    ct2d[0][0] = 1;
    for(int i=1; i<=n; i++){
        ct2d[i][0] = 1;
        for(int j=1; j<i; j++){
            ct2d[i][j] = ct2d[i-1][j] + ct2d[i][j-1];
        }
        ct2d[i][i] = ct2d[i][i-1];
    }
    return ct2d[n][n];
}

int main()
{
    cout << catalan1(10)<<' ' << catalan2(10)<<' ' << catalan3(10)
        <<' ' << catalan4(10)<<' ' << catalan5(10)<<endl;
    return 0;
}