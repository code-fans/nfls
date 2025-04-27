#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<long long, int> get_possible_sums(const string& s) {
    int n = s.size();
    vector<unordered_map<long long, int>> dp(n + 1);

    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j <= n; ++j) {
            string substr = s.substr(i, j - i);
            // 跳过前导零且长度大于1的子字符串
            if (substr.size() > 1 && substr[0] == '0') continue;

            long long num = stoll(substr);

            if (j == n) {
                dp[i][num]++;
            } else {
                for (const auto& pair : dp[j]) {
                    dp[i][pair.first + num] += pair.second;
                }
            }
        }
    }

    return dp[0];
}

int main() {
    string s;
    cin >> s;
    int n = s.size();
    long long total = 0;

    for (int k = 1; k < n; ++k) {
        string left_str = s.substr(0, k);
        string right_str = s.substr(k);

        // 检查左右部分是否有前导零问题
        if (left_str.size() > 1 && left_str[0] == '0') continue;
        if (right_str.size() > 1 && right_str[0] == '0') continue;

        auto left_sums = get_possible_sums(left_str);
        auto right_sums = get_possible_sums(right_str);

        for (const auto& l_pair : left_sums) {
            long long sum = l_pair.first;
            int l_count = l_pair.second;
            if (right_sums.count(sum)) {
                total += l_count * right_sums.at(sum);
            }
        }
    }

    cout << total << endl;

    return 0;
}