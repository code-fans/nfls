#include <bits/stdc++.h>
using namespace std;
priority_queue < long long > q;
long long a[1000000][2];
int main(){
    int n,c;
    cin>>n>>c;
    for(int i=0;i<n;i++){
        scanf("%lld%lld",&a[i][0],&a[i][1]);
    }
    long long ans=0 - (1ll<<62),ans1=0;
    for (int i = n-1; i >= 0&& c>=0; i--){
        if(a[i][0]==2){
            if(a[i][1]<0){
                q.push(a[i][1]);
                if(q.size()>c){
                    ans1+=q.top();
                    q.pop();
                }
            }else{
                ans1+=a[i][1];
            }
        }else{
            if(ans<ans1+a[i][1])
                ans=ans1+a[i][1];
            c--;
            if(q.size()>c){
                ans1+=q.top();
                q.pop();
            }
        }
    }
    if(c>=0 && ans<ans1)
        ans=ans1;
    cout<<ans<<endl;
    return 0;
}
// 5 11 1 1 1 1
// 5 1 11 1 1 1