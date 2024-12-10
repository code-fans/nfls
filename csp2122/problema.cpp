#include <bits/stdc++.h>
using namespace std;

struct listt
{
    listt * next;
    listt * prev;
    int v;

    listt(int d){
        v = d;
        next = nullptr;
        prev = nullptr;
    }
};

listt * lt[100100];

void coutans(int x){
    int ans = 0;
    listt *  p = lt[x];
    while(p->next != nullptr){
        p = p->next;
        ans ++;
    }
    p = lt[x];
    while(p->prev!=nullptr){
        p = p->prev;
        ans ++;
    }
    cout << ans+1 << ' ';
    do{
        cout << p->v << ' ';
        p = p->next;
    }while(p!=nullptr);
    cout << endl;
}

int main()
{
    //freopen("../csp2122/problem.in","r",stdin);
    int p,n;
    cin>>p>>n;
    for(int i=1; i<=p; i++){
        lt[i] = new listt(i);
    }
    int caozhuo;
    for (int i = 0; i < n; i++){
        cin>>caozhuo;
        int x,y;
        if(caozhuo==1){
            cin>>x>>y;
            lt[x]->next = lt[y];
            lt[y]->prev = lt[x]; 
        }else if(caozhuo==2){
            cin>>x>>y;
            lt[x]->next = nullptr;
            lt[y]->prev = nullptr;
        }else{
            cin>>x;
            coutans(x);
        }
    }
    return 0;
}