#include <bits/stdc++.h>
using namespace std;
int a[200010][2];
multiset <int, greater<int>> s[200010];
multiset <int> se;
int main()
{
    int n,n1, maxT=0;
    cin>>n>>n1;
    int x,y;
    for (int i = 1; i <= n; i++){
        scanf("%d%d",&x,&y);
        a[i][0]=x;
        a[i][1]=y;
        s[y].insert(x);
        if(y>maxT) maxT = y;
    }
    
    for(int i=0; i<=maxT; i++){
        if(!s[i].empty()){
            se.insert(*s[i].begin());
        }
    }

    for (int i = 0; i < n1; i++){
        scanf("%d%d",&x,&y);
        int w = a[x][0];
        int v = a[x][1];
        a[x][1]=y;

        int mv = *s[v].begin();
        se.erase(se.find(mv));
        s[v].erase(s[v].find(w));
        if(!s[v].empty()){
            se.insert(*s[v].begin());
        }

        if(!s[y].empty()){
            int my = *s[y].begin();
            se.erase(se.find(my));
        }
        s[y].insert(w);
        se.insert(*s[y].begin());

        printf("%d\n",*se.begin());
    }
    
    return 0;
}