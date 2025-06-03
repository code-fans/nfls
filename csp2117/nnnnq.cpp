#include <bits/stdc++.h>
using namespace std;
pair<long long ,long long> a[10000];
long long vis[100000]={0},mx,id;
int main(){
    long long n;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i].first;
    for(int i=1;i<=n;i++)
        cin>>a[i].second;
    sort(a+1,a+n+1,greater<pair<long long ,long long>>());
    long long ans=0;
    for (int i = a[1].first; i; i--) {
        mx=0;
        id=0;
        for (int j = 1; j <= n; j++)
            if (!vis[j]==1 && a[j].second > mx && a[j].first >= i) {
                id = j;
                mx = a[j].second;
            }
        ans += mx;
        vis[id] = 1;
    }
    cout<<ans<<endl;
    return 0;
}