#include <bits/stdc++.h>
using namespace std;
long long n,a[1000000];
long long ans=0,inf = 1ll<<60;
map<long long ,int> mp;
set<long long> p[100000];
long long s[1<<21];
long long tot=0;
void dfs1(long long i,long long sum,long long st){
    if (i==n/2+1){
        if(mp.find(sum)==mp.end())
            mp[sum] = ++tot;
        p[mp[sum]].insert(st);
        return ;
    }
    dfs1(i+1,sum,st);
    dfs1(i+1,sum+a[i],st|(1ll<<i));
    dfs1(i+1,sum-a[i],st|(1ll<<i));
}
void dfs2(long long i,long long sum,long long st){
    if(i==n+1){
        if(mp.find(sum)!=mp.end()){
            for(auto st1 : p[mp[sum]]){
                s[st1|st]=1;
            }
        }
        return ;
    }
    dfs2(i+1,sum,st);
    dfs2(i+1,sum+a[i],st|(1ll<<i));
    dfs2(i+1,sum-a[i],st|(1ll<<i));
}
int main() {
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    dfs1(1,0,0);
    dfs2(n/2+1,0,0);
    for(int i=1;i<(1<<(n+1));i++)
        if(s[i])
            ans++;
    cout<<ans<<endl;
    return 0;
}
