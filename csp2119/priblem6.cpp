#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, A[30],B[30];
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>A[i];
        cin>>B[i];
    }
    int cnt = 1<<n;
    int mask[30]={1};
    for (int i = 1; i < n; i++){
        mask[i] = 1<<i;
    }
    long long ans = 4e18;
    for (int i = 1; i < cnt; i++){
        long long xian=1, ku=0;
        for (int j = 0; j < n; j++){
            if (i & mask[j]){
                xian *= A[j];
                ku += B[j];
            }
            
        }
        long long temp = xian>ku? xian-ku : ku-xian;
        if(temp<ans) ans=temp;
    }
    cout<<ans<<endl;
    return 0;
}