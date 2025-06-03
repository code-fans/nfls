#include <iostream>
using namespace std;

vector<int> qu[10100];
int l, s[6];
int dfs(int i, int b, int a[]){
    auto it = upper_bound(qu[s[i]].begin(), qu[s[i]].end(), b);
    if (it == qu[s[i]].end()) {
        if(i<l-1)
            return dfs(i + 1, b, a);
        return 0;
    }
    a[0] = s[i];
    if (i == l - 1) {
        return 1;
    }
    int p1 = *it;
    int l1 = dfs(i + 1, p1, a+1) + 1;

    int a2[6];
    int l2 = dfs(i + 1, b, a2 );

    if (l1 > l2 || (l1 == l2 && a[0] < a2[0])) {
        return l1;
    }
    memcpy(a, a2, sizeof(int)*l2);
    return l2;
}

int main() {
    ios::sync_with_stdio(false);
    int n, m, t;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> t;
        qu[t].push_back(i);
    }
    cin >> m;
    while (m--) {
        cin >> l;
        for(int i = 0; i < l; i++){
            cin >> s[i];
        }
        int an[10] = {0};
        int ans = dfs(0, 0, an);
        cout << ans;
        for(int i = 0; i < ans; i++){
            cout << " " << an[i];
        }
        cout << endl;
    }
    return 0;
}