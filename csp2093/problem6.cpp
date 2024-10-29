#include <bits/stdc++.h>
using namespace std;

int n,m,k;
int A[40040], B[40040];

bool check(int x){
    int cut = 0;
    for(int i=0; i<n && A[i]<=x; i++){
        int bpos = upper_bound(B, B+m, x-A[i]) - B;
        cut += bpos;
        if(cut > k-1){
            return true;
        }
    }
    return false;
}

int main(){
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        cin >> A[i];
    }
    for(int i=0; i<m; i++){
        cin >> B[i];
    }
    int l = A[0] + B[0];
    int x = A[n-1] + B[m-1] + 1;

    while(l+1<x){
        int mid = (l+x) / 2;
        if(check(mid)){
            x = mid;
        } else {
            l = mid;
        }
    }
    cout << x << endl;
    return 0;
}
