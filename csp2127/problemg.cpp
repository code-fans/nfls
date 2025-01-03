#include <iostream>
using namespace std;

<<<<<<< HEAD
long long X[150100], P[105100]={0}, A[150100], B[151000], C[151000], D[151000];
=======
int X[45000], P[15100]={0}, A[15100], B[15100], C[15100], D[15100];
>>>>>>> a2ea5c02265f3f7a3d24ecbcb6ac8077afcf18b0
int N,M, minX=1510000, maxX = -1;

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("../csp2127/P2119_11.in", "r", stdin);
    cin >> N >> M;
    int t;
    for(int i=0; i<M; i++){
        cin >> t;
        if(minX>t) minX = t;
        if(maxX<t) maxX = t;
        X[i] = t;
        P[t] ++;
    }

    // x>=1
    // B - A = 2X
    // D - c = X
    // C - B > 6X ==>  C - B = 6X+ Y  Y>=1
    // A , B = A+2X , C = A+8X+Y, D = A+9X+Y

    for(int a=minX; a< maxX-9; a++){
        if(P[a]>0){
            for(int x=1; x * 9 +a < maxX; x++){
                for(int y=1; x * 9 + a + y <= maxX; y++){
                    int c = P[a] * P[a+2*x] * P[a + 8*x+y] * P[a + 9*x+y];
                    if(c>0){
                        A[a] += c;
                        B[a+2*x] += c;
                        C[a + 8*x+y] += c;
                        D[a + 9*x+y] += c;
                    }
                }
            }
        }
    }
    for(int i=0; i<M; i++){
        cout << A[X[i]]/P[X[i]] << ' '<< B[X[i]]/P[X[i]] << ' '<< C[X[i]]/P[X[i]] << ' '<< D[X[i]]/P[X[i]] << endl;
    }
    return 0;
}