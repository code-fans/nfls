#include <bits/stdc++.h>
using namespace std;
struct aa{
    int a;
    int b;
};
bool cmp(aa a,aa b){
    return a.b>b.b;
}
aa a[1000000];
int main()
{
    int n,v;
    cin>>n>>v;
    for(int i=0;i<n;i++)
        cin>>a[i].a>>a[i].b;
    sort(a,a+n,cmp);
    for (int i = 0; i < n; i++){
        if(v<a[i].a+a[i].b){
            cout<<"no"<<endl;
            return 0;
        }        v-=a[i].a;
    }
    cout<<"yes"<<endl;
    return 0;
}