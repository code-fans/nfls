#include <bits/stdc++.h>
using namespace std;
int A,B,C;
int ckn [25]={0};
set<int> states;

void dfs(int a,int b,int c){
    if(a==0) ckn[c] = 1;
    int st = a+b*100+c*10000;
    if(states.count(st)>0) return;
    states.insert(st);
    int a1=a,b1=b,c1=c;
    if(a>0){
        // a->b
        int p = min(a, B-b);
        a1 = a - p;
        b1 = b + p;
        dfs(a1,b1,c);
        // a->c
        p = min(a, C-c);
        a1 = a - p;
        c1 = c + p;
        dfs(a1,b,c1);
    }
    if(b>0){
        // b->a
        int p = min(b, A-a);
        a1 = a + p;
        b1 = b - p;
        dfs(a1,b1,c);
        // b->c
        p = min(b, C-c);
        b1 = b - p;
        c1 = c + p;
        dfs(a,b1,c1);
    }
    if(c>0){
        // c->b
        int p = min(c, B-b);
        c1 = c - p;
        b1 = b + p;
        dfs(a,b1,c1);
        // c->a
        p = min(c, A-a);
        a1 = a + p;
        c1 = c - p;
        dfs(a1,b,c1);
    }
}

int main()
{
    cin>>A>>B>>C;    
    dfs(0, 0, C);
    for (int i = 0; i < C; i++){
        if(ckn[i]==1)
            cout<<i<<' ';
    }
    cout<<C<<endl;
    return 0;
}
1392c730239402b38926b7c3c9944202