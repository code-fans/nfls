#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
long long n, t;
long long a[21][21];
unordered_map<long long, long long> dp[21][21];
int main() {
    //freopen("../csp2118/input.txt", "r", stdin);
    char c;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            t = a[i][j];
            if (i == 0 && j == 0) {
                dp[i][j][t] = 1;
            } else {
                if (i > 0) {
                    for (const auto& pair : dp[i - 1][j]) {
                        dp[i][j][pair.first ^ t] += pair.second;
                    }
                }
                if (j > 0) {
                    for (const auto& pair : dp[i][j - 1]) {
                        dp[i][j][pair.first ^ t] += pair.second;
                    }
                }
            }
        }
    }
    long long ans = 0;
    for (int i = n - 1; i > 0; i--) {
        int j;
        for (j = n - 1; j >= n - i; j--) {
            t = a[i][j];
            if (i == n - 1 && j == n - 1) {
                dp[i][j][t] = 1;
            } else {
                if (i < n - 1) {
                    for (const auto& pair : dp[i + 1][j]) {
                        dp[i][j][pair.first ^ t] += pair.second;
                    }
                }
                if (j < n - 1) {
                    for (const auto& pair : dp[i][j + 1]) {
                        dp[i][j][pair.first ^ t] += pair.second;
                    }
                }
            }
        }
        j++;
        for (const auto& pair : dp[i - 1][j]) {
            if (dp[i][j].count(pair.first) > 0) {
                long long l = pair.second * dp[i][j][pair.first];
                ans += l;
            }
        }
        for (const auto& pair : dp[i][j - 1]) {
            if (dp[i][j].count(pair.first) > 0) {
                long long l = pair.second * dp[i][j][pair.first];
                ans += l;
            }
        }
    }
    cout << ans << endl;
    return 0;
}