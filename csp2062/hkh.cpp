#pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
int zhong, n, ans[10000005], zh, jia,ge;
int main() {
    scanf("%d%d",&zhong,&n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d%d",&ge,&zh,&jia);
        int w=1;
        while(w<=ge){
            for (int j = zhong; j >= w*zh; j--) {
                ans[j] = max(ans[j], ans[j-w*zh]+w*jia);
            }
            ge-=w;
            w<<=1;
        }
        if(ge>0){
            for (int j = zhong; j >= ge*zh; j--) {
                ans[j] = max(ans[j], ans[j-ge*zh]+ge*jia);
            }
        }
    }
    printf("%d\n",ans[zhong]);
    return 0;
}