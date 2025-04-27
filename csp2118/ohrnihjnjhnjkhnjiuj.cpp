#include <bits/stdc++.h>
using namespace std;

// 获取n的所有因数（有序）
vector<long long> get_factors(long long n) {
    vector<long long> factors;
    for (long long i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            factors.push_back(i);
            if (i != n / i) factors.push_back(n / i);
        }
    }
    sort(factors.begin(), factors.end());
    return factors;
}

// 回溯搜索：从factors[start:]中选择k个不同因数，乘积为n
bool backtrack(vector<long long>& factors, int start, int k, long long product, long long n) {
    if (k == 0) return product == n;
    for (int i = start; i < factors.size(); ++i) {
        if (product * factors[i] > n) break; // 提前终止
        if (backtrack(factors, i + 1, k - 1, product * factors[i], n)) return true;
    }
    return false;
}

// 主逻辑
bool solve(long long n, int k) {
    if (k == 1) return true; // 特例：k=1时只需n本身
    long long min_product = 1;
    for (int i = 1; i <= k; ++i) {
        if (min_product > n / i) return false; // k! > n时无解
        min_product *= i;
    }
    if (min_product > n) return false;
    vector<long long> factors = get_factors(n);
    return backtrack(factors, 0, k, 1, n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        long long n;
        int k;
        cin >> n >> k;
        cout << (solve(n, k) ? "TAK" : "NIE") << '\n';
    }
    return 0;
}