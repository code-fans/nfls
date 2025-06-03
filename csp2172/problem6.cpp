#include <bits/stdc++.h>
using namespace std;
int cnt[1000007];
bool vis[1000007];
int n;
int main() {
    cin>>n;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        cnt[x]++;
    }
    int ans=0;
    for(int i=0;i<=1000000;i++){
        if(!cnt[i])
            continue;
        if(cnt[i]==1&&!vis[i])
            ans++;
        for(int j=2;j*i<=1000000;j++)
            vis[j*i]=true;
    }
    cout<<ans<<endl;
    return 0;
}
