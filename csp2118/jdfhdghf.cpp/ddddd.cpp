#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[1000001], ans[1000001];
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin>>a[i];
    for (int i = 1; i <= n; i++) {
        if (i <= 2)
            ans[i] = a[i] + a[i - 1];
        else
            ans[i] = max(a[i] + ans[i - 2], a[i] + a[i - 1] + ans[i - 3]);
        ans[i] = max(ans[i], ans[i - 1]);
    }
    cout << ans[n]<<endl;
    return 0;
}