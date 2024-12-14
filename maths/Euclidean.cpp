#include<iostream>

using namespace std;
// 拓展欧几里得算法
int exgcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    //int r = exgcd(b, a % b, y, x);
    //y -= a / b * x;
    
    int r = exgcd(b, a % b, x, y);
    int temp = x;
    x = y;
    y = temp - a / b * y;
    
    return r;
}

int exgcd2(int a, int b, int& x, int& y) {
    int s0=1,s1=0,s2;
    int t0=0,t1=1,t2;
    while(b!=0){
        int q=a/b, r=a%b;
        s2 = s0 - s1*q;
        t2 = t0 - t1*q;
        a = b; b = r;
        s0=s1; s1=s2;
        t0=t1; t1=t2;
    }
    x=s0; y=t0;
    return a;
}


int main(){
    int s,t;
    cout << exgcd2(105, 66, s, t)<< endl;
    cout <<s << ' ' << t<< endl;
    return 0;
}