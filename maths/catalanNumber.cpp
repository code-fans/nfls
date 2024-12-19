#include <iostream>
#include <bitset>
using namespace std;

// f(n) = sum ( f(0)f(n-1), f(1)f(n-2), f(2)f(n-3),......, f(n-1)f(0))
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

// f(n) = f(n-1) * (4n-2) /(n+1)
long long catalan2(int n){
    cn[0] = cn[1] = 1;
    for(int i=2; i<=n; i++){
        cn[i] = cn[i-1] * (4*i - 2) / (i+1);
    }
    return cn[n];
}

// f(n) = C(2n, n) /(n+1)
long long catalan3(int n){
    long long ct = 1;
    for(int i=0;i<n;i++){
        // ct *= (2*n-i) / (i+1); 改成这样行不行
        ct = ct * (2*n-i) / (i+1);
    }
    return ct / (n+1);
}

// f(n) = C(2n, n) - C(2n, n+1)
long long catalan4(int n){
    long long ct = 1;
    for(int i=0;i<n;i++){
        // ct *= (2*n-i) / (i+1); 改成这样行不行
        ct = ct * (2*n-i) / (i+1);
    }
    long long ctn1 = ct * n / (n+1);
    return ct - ctn1;
}
// 爬楼梯模拟法
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
    int n = 50;
    cout << catalan1(n)<<' ' << catalan2(n)<<' ' << catalan3(n)
        <<' ' << catalan4(n)<<' ' << catalan5(n)<<endl;
    return 0;
}