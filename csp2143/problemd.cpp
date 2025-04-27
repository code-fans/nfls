#include <bits/stdc++.h>
using namespace std;
multiset <int>  bigdata;
multiset <int, greater<int> >  smalldata;
int a[550000];
int main()
{
    int m,k,n;
    cin>>m>>k>>n;
    for (int i = 0; i < k; i++){
        bigdata.insert(0);
    }
    for (int i = 0; i <= n-k; i++){
        smalldata.insert(0);
    }
    long long ans=0;
    for (int i = 0; i < n; i++){
        int c = * smalldata.begin();
        int x,y;
        scanf("%d%d",&x,&y);
        if(a[x]<=c){
            smalldata.erase(smalldata.find(a[x]));
            smalldata.insert(y);
        }else{
            bigdata.erase(bigdata.find(a[x]));
            bigdata.insert(y);
            ans+=y-a[x];
        }
        a[x]=y;
        int b = * bigdata.begin();
        c = * smalldata.begin();
        if(b<c){
            smalldata.erase(smalldata.find(c));
            smalldata.insert(b);
            bigdata.erase(bigdata.find(b));
            bigdata.insert(c);
            ans+=c-b;
        }
        printf("%lld\n",ans);
    }
    
    return 0;
}