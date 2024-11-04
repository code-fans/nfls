#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, K, t, halft, a, ans=0;
    int data[200] = {0};
    cin >> N >> K;
    for(int i=0; i<N; i++){
        cin >> a;
        if(a==1){
            data[i%K] ++;
        }
    }
    t = N / K; halft = t/2;
    for(int i=0; i<K; i++){
        ans +=  data[i]>halft? t-data[i]: data[i];
    }
    cout << ans << endl;
    return 0;
}