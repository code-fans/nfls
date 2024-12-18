#include<iostream>

using namespace std;
// 拓展欧几里得算法
// a*x + b*y = gcd(a,b) = gcd(b, a%b) = b*x1 + (a%b)y1
// a*x + b*y = b*x1 +(a-a/b*b)y1
//           = a*y1 +b(x1-a/b)y1 
// x = y1 , y = (x1-a/b)y1
// 欧几里得（辗转相除算法）最后一行 gcd(a,b) , 0 对应 1，0 肯定可以保证 gcd(a,b) * 1 = 0 * 0 = gcd(a,b)
// 然后逐步会退，每一步都保证 a*x + b*y = gcd(a,b) 成立
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
    cout << x <<'\t'<< y << endl;
    return r;
}

//
int exgcd2(int a, int b, int& x, int& y) {
    int s0=1,s1=0,s2;
    int t0=0,t1=1,t2;
    while(b!=0){
        cout << s1 << '\t' << t1 << endl;
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
<<<<<<< HEAD
    int s,t, n, m;
    cin >> n >>m;
    cout << exgcd(n, m, s, t)<< endl;
    cout << "RESULT "<<s << ' ' << t<< endl;
     cout << exgcd2(n, m, s, t)<< endl;
    cout << "RESULT "<<s << ' ' << t<< endl;
=======
    int s,t;
    cout << exgcd2(105, 66, s, t)<< endl;
    cout <<s << ' ' << t<< endl;
>>>>>>> 7a9c9fff0f64192f4ac2be2f7e560f802c101f8d
    return 0;
}