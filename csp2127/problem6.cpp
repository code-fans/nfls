#include <bits/stdc++.h>
using namespace std;
int main() {
    int a[10000] = { 0 }, n, a1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a1;
        a[a1 + 200]++;
    }
    int ans = 0;
    for (int i = 1; i <= 406; i++) {
        for (int j = 0; j < 406; j++) {
            if (a[j] != 0) {
                int size1 = 0;
                for (int N=j; N <= 406; N += i) {
                    if (a[N])
                        size1++;
                    else
                        break;
                }
                ans = max(ans, size1);
            }
        }
    }
    for (int i = 0; i <= 406; i++)
        if (a[i] > ans)
            ans = a[i];
    cout << ans << endl;
    return 0;
}