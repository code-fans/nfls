#include<iostream>

using namespace std;
// 拓展欧几里得算法
// a*x + b*y = gcd(a,b) = gcd(b, a%b) = b*x1 + (a%b)y1
// a*x + b*y = b*x1 +(a-a/b*b)y1
//           = a*y1 +b(x1-a/b)y1 
// x = y1 , y = (x1-a/b)y1
// 欧几里得（辗转相除算法）最后一行 gcd(a,b) , 0 对应 1，0 肯定可以保证 gcd(a,b) * 1 = 0 * 0 = gcd(a,b)
// 然后逐步回退，每一步都保证 a*x + b*y = gcd(a,b) 成立
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
    // cout << x <<'\t'<< y << endl;
    return r;
}
// https://www.bilibili.com/video/BV1vL4y1L7c4/
// r0=a r1=b                      s0=1, s1=0, t0=0, t1=1 =>  a*s[i]+b*s[i] = r[i]
// r2=r0%r1 q1=r0/r1 r0=q1*r1+r2  r2 = r0 -q1*r1      => r[i] = r[i-2] -q[i-1]r[i-1]
// r3=r1%r2 q2=r1/r2 r1=q2*r2+r3  r3 = r1 -q2*r2      => r[i] = r[i-2] -q[i-1]r[i-1]
// 
// 数学归纳法
//  a(s[i-2]-s[i-1]q[i-1]) + b(t[i-2]-t[i-1]q[i-1])
// =a*s[i-2]-a*s[i-1]q[i-1]+ b*t[i-2]-b*t[i-1]q[i-1]
// =(a*s[i-2]+b*t[i-2]) -(a*s[i-1]+b*t[i-1])*q[i-1]
// = r[i-2] -r[i-1]q[i-1]
// = r[i]
// => a*s[i] + b*r[i] = r[i] = a(s[i-2]-s[i-1]q[i-1]) + b(t[i-2]-t[i-1]q[i-1])
// => s[i]=s[i-2]-s[i-1]q[i-1], r[i]=t[i-2]-t[i-1]q[i-1]
//当 r[n+1] == 0 时 r[n] = gcd(a,b) , s[n],t[n]就是方程 a*x+b*y=gcd(a,b)的解
int exgcd2(int a, int b, int& x, int& y) {
    int s0=1,s1=0,s2;
    int t0=0,t1=1,t2;
    while(b!=0){
        // cout << s1 << '\t' << t1 << endl;
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

// 求a对于b的逆元（乘法逆元），要求 a和m互素（互质）
// a * s = 1 (MOD m)
int inverseElement(int a, int m){
    int x, y;
    exgcd2(a, m, x, y);
    return (x+m)%m; // s
}

int main(){
    int s,t, n, m;
    cin >> n >>m;
    cout << exgcd(n, m, s, t)<< endl;
    cout << "RESULT "<<s << ' ' << t<< endl;
    cout << "RE "<< inverseElement(n, m)<< endl;
    return 0;
}