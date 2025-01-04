#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

pair<long long, long long> ball[1001000];
long long ballCount[100];

int main() {
    long long n, k, l = 0;
    cin >> n >> k;
    long long m, p;
    for (int i = 1; i <= k; i++) {
        cin >> m;
        for (int j = 0; j < m; j++) {
            cin >> p;
            ball[l].first = p;
            ball[l].second = i;
            l++;
        }
    }
    sort(ball, ball + l);
    long long b = 0, e = 0, bc = 0, ans = 1e18;
    while (e < l) {
        while (bc < k && e < l) {
            ballCount[ball[e].second]++;
            if (ballCount[ball[e].second] == 1)
                bc++;
            e++;
        }
        /*if(bc==k){
            int s = ball[e-1].first - ball[b].first;
            if(s < ans) ans = s;
        }*/
        while (bc == k && b < l) {
            ballCount[ball[b].second]--;
            if (ballCount[ball[b].second] == 0) {
                int s = ball[e - 1].first - ball[b].first;
                if (s < ans)
                    ans = s;
                bc--;
            }
            b++;
        }
        /*while(b<l && ball[b].first == ball[b-1].first){
            ballCount[ball[b].second] --;
            if(ballCount[ball[b].second]==0) bc--;
            b++;
        }*/
    }
    cout << ans << endl;
    return 0;
}
