#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;
int N, K;
int shu[100100];

int main(){
    // freopen("../csp2103/input.txt", "r", stdin);
    scanf("%d%d",&N, &K);
    for(int i=0; i<N; i++){
        scanf("%d",&shu[i]);
    }
    K++;
    unordered_map<int, int> keySum;
    keySum.reserve(100100);

    int l=0,r=0, ans=0;
    while(r<N){
        while(l<r && keySum.size() >= K){
            keySum[shu[l]] --;
            if(keySum[shu[l]]==0){
                // key.erase(shu[l]);
                keySum.erase(shu[l]);
            }
            l++;
        }
        while(r<N && ( keySum.size() < K || keySum.count(shu[r]) >0 )){
            keySum[shu[r]] ++; 
            if(ans < keySum[shu[r]] ){
                ans = keySum[shu[r]] ;
            }
            r++;
        }
    }
    printf("%d\n", ans);
    return 0;
}