#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, A[30];
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> A[i];
    }

    int cnt = 1 << n;
    int mask[30]={1};
    for(int i=1; i<n; i++){
        mask[i] =  1<<i;
    }

    int ans=2e9;
    for(int i=0; i<cnt; i++){
        int res=0, now=0;
        for(int j=0;j<n;j++){
            now |= A[j];
            if(i & mask[j]){
                res ^= now;
                now = 0;
            }
        }
        res ^= now;
        if(res<ans) ans = res;
    }
    cout << ans << endl;
    return 0;
}