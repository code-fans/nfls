#include <bits/stdc++.h>
using namespace std;
int N, K;
int diam[100010], lml[100010];
int main(){
    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> diam[i];
    }
    sort(diam, diam+N);
    int maxl=0, l=0,r=0;
    //求 前缀， 最长子窜
    for(;r<N;r++){
        while( diam[r] - diam[l] > K){
            l++;
        }
        int cl = r-l+1;
        if(maxl<cl){
            maxl = cl;
        }
        lml[r] = maxl;
    }
    int ans = 0;

    r=N-1, l=N-1;
    while(l>0){
        l--;
        while(r>l && diam[r] - diam[l] > K) r--;
        int cl = r-l+1;
        if(cl + lml[l-1] > ans){
            ans = cl + lml[l-1];
        }
    }
    
    cout << ans << endl;
    return 0;
}