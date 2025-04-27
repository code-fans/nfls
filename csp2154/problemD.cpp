#include <iostream>
#include <cstring>

using namespace std;

long long zdd(long long  a,long long b){
    while (b){
        a%=b;
        swap(a,b);
    }
    return a;
}

long long C, sl[100100];
char    cl[100100];
int main(){
    // freopen("../csp2154/input.txt", "r", stdin);
    int n;
    cin >> n;
    while(n--){
        int m;
        C = 0;
        long long TB=0, TW=0, PB,PW, PT;
        char t, pt='k';
        cin >> m;
        while(m--){
            cin >> PT >> t;
            if(t == 'B') TB += PT; else TW += PT;
            if(t == pt){
                sl[C-1] += PT;
            } else {
                pt = t;
                cl[C] = t;
                sl[C] = PT;
                C++;
            }
        }
        if(TB==0 || TW==0){
            cout << TB+TW<< endl;
            continue;
        }
        long long gys = zdd(TB,TW);
        if(gys==1){
            cout << 1 << endl;
            continue;
        }
        TB /= gys;
        TW /= gys;
        PB=0; PW=0;
        int ans = 0;
        for(int i=0; i<C; i++){
            t = cl[i];
            if(t == 'B'){
                if(PW!=0 && PW%TW==0){
                    long long bs = PW/TW;
                    if(PB < bs * TB && PB + sl[i] >= bs * TB){
                        ans ++;
                        PW = 0;
                        PB = PB+ sl[i] - bs * TB;
                    } else {
                        PB += sl[i];
                    }
                }  else {
                    PB += sl[i];
                }
            } else {
                if(PB!=0 && PB%TB==0){
                    long long bs = PB/TB;
                    if(PW < bs * TW && PW + sl[i] >= bs * TW){
                        ans ++;
                        PB = 0;
                        PW = PW+ sl[i] - bs * TW;
                    } else {
                        PW += sl[i];
                    }
                }  else {
                    PW += sl[i];
                }
            }
        }
        cout << ans << endl;

    }
    return 0;
}