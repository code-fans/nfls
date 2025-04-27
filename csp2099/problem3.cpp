#include <iostream>
#include <cstring>
using namespace std;
#define ll long long
const int N = 1e5 + 10;
int a[N];
int nxt[N][30], pos[20];
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        memset(pos, 0, sizeof pos);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            for (int j = 0; j <= 20; j++)
                nxt[i][j] = n + 1;
        }
        for (int i = n; i >= 1; i--)
        {
            if (!pos[a[i]])
            {
                nxt[i][0] = n + 1;
                pos[a[i]] = i;
            }
            else
            {
                nxt[i][0] = pos[a[i]];
                pos[a[i]] = i;
            }
        }
        for (int j = 1; j <= 20; j++)
        {
            for (int i = 1; i <= n; i++)
            {
                if (nxt[i][j - 1] + 1 <= n)
                    nxt[i][j] = nxt[nxt[i][j - 1] + 1][j - 1];
            }
        }
        int q;
        cin >> q;
        while (q--)
        {
            int l, r;
            cin >> l >> r;
            int ii = l;
            int ans = 0;
            while (ii <= r)
            {
                while (ii <= r && nxt[ii][0] > r)
                {
                    ii++;
                    ans++;
                }
                if (ii > r)
                    break;
                for (int j = 20; j >= 0; j--)
                {
                    if (nxt[ii][j] <= r)
                    {
                        ii = nxt[ii][j];
                        break;
                    }
                }
                ii++;
            }
            cout << ans << endl;
        }
    }
}