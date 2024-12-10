#include <iostream>
#include <unordered_map>
#include <cstdio>
using namespace std;

unordered_map<int, int> timeMap;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, t, m, x;
    scanf("%d",&n);
    while(n--){
        scanf("%d%d",&t,&m);
        while(m--){
            scanf("%d",&x);
            timeMap[x] = t;
        }
        int ans = 0;
        for(unordered_map<int, int>::iterator p = timeMap.begin(); p!=timeMap.end(); p++){
            if(p->second > t-86400){
                ans ++;
            }
        }
        printf("%d\n",ans);
    }

    return 0;
}