#include <iostream>
#include <bitset>
using namespace std;

// https://www.luogu.com.cn/problem/P7071
// 洛谷的P7071你觉得这个代码能正确吗？
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


int bitCount2(int n){
    int ans = 0;
    bool a = n<0;
    if(a)
        n = ~n;
    while(n){
        ans+=n%2;
        n/=2;
    }
    if(a)
        ans = 32-ans;
    return ans;
}


int bitCount3(int n){
    int ans=0;
    cin>>n;
    while (n){
        ans++;
        // string str = bitset<32>(n).to_string();
        cout<< bitset<32>(n) << ' '<< n << '\t' << bitset<32>(n-1) << ' ' << n-1 << endl;
        n&=(n-1);
    }
    return ans;
}

//汉明距离
int hammingDistance(int x, int y){
    return bitCount(x ^ y);
}

// 最右侧的 1 
int rightMostOne(int n) {
    return n & (-n);
}

// 最左侧的 1 注意不适合负数，负数右移位 会补1
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
    int n=12345678;
    chaifen(n);
    cout << endl;
    cout << leftMostOne(-1) << endl;
    cout << rightMostOne(-1) << endl;
    cout << hammingDistance(n, n-leftMostOne(n)) << endl;
    return 0;
}