#include <iostream>
using namespace std;

void chaifen(int n){
    if(n==0) return;
    int p = n & (-n);
    // chaifen(n-p);
    chaifen(n & (n-1));
    cout << p << ' ';
}

// Brian Kernighan 算法?  布莱恩·柯林汉 算法
int bitCount(int n){
    int bs = 0;
    while(n!=0){
        bs++;
        n &= n-1;
    }
    return bs;
}

//汉明距离
int hammingDistance(int x, int y){
    return bitCount(x ^ y);
}

// 最右侧的 1 
int rightMostOne(int n) {
    return n & (-n);
}

// 最左侧的 1 
int leftMostOne(int n) {
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
    cout << leftMostOne(n) << endl;
    cout << bitCount(n) << endl;
    cout << hammingDistance(n, n-leftmostOne(n)) << endl;
    return 0;
}