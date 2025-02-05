#include <bits/stdc++.h>
using namespace std;
int a,b,ans[100000000]={0},zh[10000000],jia[10000000];
int main()
{
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < m; i++) {
        cin >> zh[i] >> jia[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = n - zh[i]; j >= 0; j--) {
            if (ans[j + zh[i]] < ans[j] + jia[i]) {
                ans[j + zh[i]] = ans[j] + jia[i];
            }
        }
    }
    cout << ans[n] << endl;
    return 0;
}