#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long b, n;
    cin >> n;
    long long maxV =  1e18, maxP = -1;
    for (int i = 1; i <= n; i++) {
        cin >> b;
        if(b<= maxV) {
            maxV = b;
            maxP = i;
        }
    }
    cout << maxP << endl;
    return 0;
}