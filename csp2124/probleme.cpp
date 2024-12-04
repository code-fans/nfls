#include <iostream>
#include <string.h>
#include <cmath>
using namespace std;
long long ans[101000][550],c[100000][2],and1=0,h1=0;
int main(){
    long long W, N, l, r, v;
    cin >> W >> N;
    memset(ans,-1,sizeof(ans));
    ans[0][0] = 0;
    long long p=0;
    for(int i=0; i<N; i++){
        cin >> l >> r >> v;
        p += r;
        long long beginP = min(p,W);
        long long m = r-l+1;
        and1=0;
        c[0][1] = beginP-l;
        c[0][0] = ans[i-1][beginP-l];
        h1 = 1;
        for(int j=0; j<=W; j++){
            if(c[and1][1] == j-m )
                and1++;
            while(h1>and1 && c[h1-1][0]<=ans[i-1][j])
                h1--;
            c[h1][1]=j;
            c[h1][0]=ans[i-1][j];
            h1++;
            if(c[and1][0] != -1 && ans[i-1][j+r] < c[and1][0] +v ){
                ans[i][j] = c[and1][0] + v ;
            }
        }
    }
    cout << ans[N-1][W] << endl;
    return 0;
}