#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;
typedef long long ll;

ll ans[100100], q[100100][2];
int main()
{
    ios::sync_with_stdio(false);
    ll n,W, v,w,m;
    cin>>n>>W;
    for(int i=0;i<n;i++){
        cin>>v >> w >> m;
        m = min(m,W/w);
        for(int j=0; j<w; j++){
            int head = 0, tail = 0;
            int maxCnt = (W-j)/w;
            for(int k=0; k<=maxCnt; k++){
                while(head<tail && ans[j+k*w] - k*v > q[tail-1][0]) tail--;
                q[tail][0] = ans[j+k*w] - k*v;
                q[tail++][1] = k;
                while(head<tail && q[head][1] < k-m) head++;
                ans[j+k*w] = max(ans[j+k*w], q[head][0]+ k*v);
            }
        }
    }
    cout << ans[W] << endl;
    return 0;
}