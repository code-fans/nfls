#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;
typedef long long ll;

struct DS {
    int t, x, s;
    bool operator<(DS &ds) { return t < ds.t; }
};

ll dp[100100];
int pos[100100];
DS ds[100100];

int main() {
    int n, allstate=0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ds[i].t >> ds[i].x >> ds[i].s;

    }
    memset(pos, -1, sizeof(pos));
    pos[0] = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll maxnum = 0;
        int state = 0;
        for (int j = ds[i].t-1; j >=0; j--) {
            if (pos[j] >= 0 && abs(ds[i].x - pos[j]) <= ds[i].t - j){
                if( maxnum < dp[j] + ds[i].s) {
                    maxnum = dp[j] + ds[i].s;
                }
                state |= 1 << pos[j];
                if(state == allstate) break;
            }
        }
        if (maxnum) {
            dp[ds[i].t] = maxnum;
            pos[ds[i].t] = ds[i].x;
            ans = max(ans, maxnum);
        }
        allstate |= 1 << ds[i].x;
    }
    cout << ans << endl;
    return 0;
}