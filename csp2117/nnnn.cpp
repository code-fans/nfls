#include <bits/stdc++.h>
using namespace std;
pair <long long ,long long> a[10000000];
long long c[10000000];
int main(){
    long long n,m;
    cin>>n>>m;
    for (int i = 0; i < n; i++){
        long long b,d; 
        cin>>b>>d;
        a[i]={b,d};
    }
    for (int i = 0; i < m; i++)
        cin>>c[i];
    sort(a,a+n);
    sort(c, c + m);
    long long ans=0;
    int j=0;
    priority_queue < long long > q;
    for(int i=0;i<m;i++){
        while(j<n && a[j].first<=c[i])
            q.push(a[j++].second);
        if(!q.empty()){
            ans+=q.top();
            q.pop();
        }
    }
    cout<<ans<<endl;
    return 0;
}