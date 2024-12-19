#include <bits/stdc++.h>
using namespace std;
struct sum
{
    long long a,b;

    friend bool operator > ( sum & a, sum & b) {
        if(a.a!=b.a)
            return a.a<b.a;
        return a.b<b.b;
    }
};
// 仿函数
struct cmp{
    bool operator () ( sum & a, sum & b) {
        if(a.a!=b.a)
            return a.a<b.a;
        return a.b<b.b;
    }
};

priority_queue < sum, vector<sum>, cmp > q;

int main()
{
    long long n,m;
    long long ans=0;
    cin>>n>>m;
    sum num;
    for (int i = 0; i < n; i++){
        cin>>num.a>>num.b;
        q.push(num);
    }
    for (int i = 0; i < m&&!q.empty(); i++){
        while (!q.empty()){
            if(q.top().a+i<=m){
                ans+=q.top().b;
                q.pop();
                break;
            }
            q.pop();
        }
    }
    cout<<ans<<endl;
    return 0;
}