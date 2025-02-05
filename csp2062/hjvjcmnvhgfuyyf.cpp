#include <bits/stdc++.h>
using namespace std;
long long zhong, n, ans[100000], zh[100000], jia[100000];
int main() {
    cin >> zhong >> n;
    int m;
    for (int i = 1; i <= n; i++) {
        cin>>m;
        for (int j = zhong; j > m; j--){
            ans[j]+=ans[j-m];
        }
        ans[m]++;
    }
    ans[0]=1;
    for (int i = zhong; i >= 0; i--){
        if(ans[i]>=1){
            cout<<i<<endl;
            return 0;
        }
    }
    return 0;
}