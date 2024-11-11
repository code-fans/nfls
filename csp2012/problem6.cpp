#include <iostream>
#include <string>
using namespace std;
#define PX  37
unsigned int zfchash[1000010];
int main() {
    long long ans = 0;
    string str, str1;
    cin >> str >> str1;
    int sl = str.size(), sl1 = str1.size();
    unsigned int hx = 0;
    for (int i = 1; i <= sl; i++) {
        hx = hx * PX + str[i - 1];
        zfchash[i] = hx;
    }
    unsigned int zchx = 0, p = 1;
    for (int i = 0; i < sl1; i++) {
        zchx = zchx * PX + str1[i];
        p *= PX;
    }
    for (int i = sl1; i <= sl; i++) {
        unsigned int tempHx = zfchash[i] - zfchash[i - sl1] * p;
        if (tempHx == zchx)
            ans++;
    }
    cout << ans << endl;
    return 0;
}