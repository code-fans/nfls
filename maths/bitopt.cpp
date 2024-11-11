#include <iostream>
using namespace std;

void chaifen(int n){
    if(n==0) return;
    int p = n & (-n);
    // chaifen(n-p);
    // Brian Kernighan算法?
    chaifen(n & (n-1));
    cout << p << ' ';
}

int bitCount(int n){
    int bs = 0;
    while(n!=0){
        bs++;
        n &= n-1;
    }
    return bs;
}

int hammingDistance(int x, int y){
    return bitCount(x ^ y);
}

int leftmostOne(int n) {
    // 确保 第一个 1 后面的所有位 都是 1
    n |= (n >> 1);
    n |= (n >> 2);
    n |= (n >> 4);
    n |= (n >> 8);
    n |= (n >> 16);
    return n - (n >> 1);
}

int main(){
    int n=12356;
    chaifen(n);
    cout << endl;
    cout << leftmostOne(n) << endl;
    cout << bitCount(n) << endl;
    cout << hammingDistance(n, n-leftmostOne(n)) << endl;
    return 0;
}