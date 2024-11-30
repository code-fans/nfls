#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;
long long ans[10100];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int W, N, l, r, v;
    cin >> W >> N;
    memset(ans,-1,sizeof(ans));
    ans[0] = 0;
    int p=0;
    for(int i=0; i<N; i++){
        cin >> l >> r >> v;
        p += r;
        int beginP = min(p,W);
        for(int j=beginP; j>=l; j--){
            int b = max(j-l,0);
            int e = max(j-r,0);
            //bool f = false;
            for(int k=b; k>= e; k--){
                if(ans[k] != -1 && ans[j] < ans[k] + v){
                    ans[j] =  ans[k] + v;
                    break;
                }
            }
            //if(f) break;
        }
    }
    cout << ans[W] << endl;
    
    return 0;
}