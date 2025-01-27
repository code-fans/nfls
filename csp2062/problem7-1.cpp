#pragma GCC optimize(3)
#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <utility>

using namespace std;
typedef long long ll;

struct DS {
    ll t, x, s;
};

vector<pair<ll, ll> > dp[5];

DS ds[100100];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ds[i].t >> ds[i].x >> ds[i].s;
    }

    ll ans = 0;
    dp[0].push_back({0,0});
    for (int i = 0; i < n; i++) {
        ll maxnum = -1;
        for (int j = 0; j < 5; j++) {
            int l = dp[j].size();
            for(int k=l-1; k>=0; k--){
                if (abs(ds[i].x - j) <= ds[i].t - dp[j][k].first){
                    if( maxnum < dp[j][k].second + ds[i].s ){
                        maxnum = dp[j][k].second + ds[i].s;
                    }
                    break;
                }
            }
        }
        if (maxnum >= 0 ) {
            dp[ds[i].x].push_back({ ds[i].t, maxnum});
            ans = max(ans, maxnum);
        }
    }
    cout << ans << endl;
    return 0;
}