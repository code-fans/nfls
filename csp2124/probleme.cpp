#include <iostream>
#include <string.h>
#include <cmath>

using namespace std;
long long ans[10100];
int main(){
    int W, N, l, r, v;
    cin >> W >> N;
    memset(ans,-1,sizeof(ans));
    ans[0] = 0;
    for(int i=0; i<N; i++){
        cin >> l >> r >> v;
        for(int j=W; j>=l; j--){
            int b = max(j-r,0);
            //if(ans[b]==-1) continue;
            for(int k=b; k<=j-l; k++){
                if(ans[k] != -1 && ans[j] < ans[k] + v){
                    ans[j] =  ans[k] + v;
                }
            }
        }
    }
    cout << ans[W] << endl;
    
    return 0;
}