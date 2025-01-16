#include <bits/stdc++.h>
using namespace std;
int guangli[10000];
void qlas(int a[],int num){
    a[num]++;
    if(num==0)
        return ;
    qlas(a,guangli[num]);
}
int main()
{
    int n,m,r,a[1000]={0},p;
    cin>>n;
    for (int i = 1; i < n; i++){cin>>guangli[i];}
    cin>>m;
    for (int i = 0; i < m; i++){
        cin>>r;
        for (int j = 0; j < r; j++){
            cin>>p;
            qlas(a,p);
        }
        for (int j = n; j >= 0; j--) i(a[j]==r){cout<<j<<endl;break;}
    }
    return 0;
}
// 0 0 0 2 2
// 2 0 1 0 0
// 0
/*

5
0 0 2 2
3
2 3 4
3 2 3 4
2 1 4

*/