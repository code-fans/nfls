#include <iostream>
using namespace std;

void chaifen(int n){
    if(n==0) return;
    int p = n & (-n);
    // chaifen(n-p);
    chaifen(n & (n-1));
    cout << p << ' ';
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

    cout << leftmostOne(15) << endl;
    return 0;
}