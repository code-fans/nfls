#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int> > q;
int a[100000][2],c[100000];
int main(){
    int n;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>a[i][0];
    }
    for (int i = 0; i < n; i++){
        cin>>a[i][1];
    }
    for (int i = 0; i < n-1; i++){
        cin>>c[i];
    }
    int t,ans=0,s=0;
    cin>>t;
    for (int i = 1; i <= n; i++){
        s=0;
        int t1=t;
        for (int j = 0; j < i; j++){
            q.push({a[j][0],a[j][1]});
            if(j!=0)
                t1-=c[j-1];
        }
        while(!q.empty()&&t1>=1){
            s+=q.top().first;
            if(q.top().first-q.top().second>=1)
                q.push({q.top().first-q.top().second,q.top().second});
            q.pop();
            t1--;
        }
        if(s>ans){
            ans=s;
        }
    }
    cout<<ans<<endl;
    return 0;
}