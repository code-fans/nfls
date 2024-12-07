#include <bits/stdc++.h>
using namespace std;
long long a[1100][1100]={{0}};
long long p[1100];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long n,x,x1,y,y1;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>x>>y>>x1>>y1;
        for (int j = x; j < x1; j++){
            for (int k = y; k < y1; k++){
                a[j][k]++;
            }
        }
    }
  
    for (int j = 0;j <= 1000; j++){
        for (int k = 0; k <= 1000; k++){
            p[a[j][k]]++;
        }
    }

    for(int i=1;i<=n;i++){
        cout<<p[i]<<endl;
    }
    return 0;
}