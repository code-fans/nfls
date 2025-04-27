#include <bits/stdc++.h>
using namespace std;
long long a[200200][2];
multiset<long long, greater<long long>> s[200200];
multiset<long long> se;
int main() {
    long long  n, n1;
    cin >> n >> n1;
    long long x, y,maxt=0;
    for (int i = 1; i <= n; i++) {
        scanf("%lld%lld", &x, &y);
        a[i][0] = x;
        a[i][1] = y;
        s[y].insert(x);
        maxt=max(y,maxt);
    }
    for (int i = 0; i <= maxt; i++)
        if(!s[i].empty())
            se.insert(*s[i].begin());
    for (int i = 0; i < n1; i++) {
        scanf("%lld%lld", &x, &y);
        long long w = a[x][0], v = a[x][1];
        a[x][1] = y;
        se.erase(se.find( *s[v].begin()) );
        s[v].erase(s[v].find(w));
        if(!s[v].empty()){
            se.insert(*s[v].begin());
        }
        if(!s[y].empty())
            se.erase(se.find(*s[y].begin()));
        s[y].insert(w);
        se.insert(*s[y].begin());
        printf("%lld\n", *se.begin());
    }

    return 0;
}