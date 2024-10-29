#include <bits/stdc++.h>
using namespace std;

#define CEIL(a,b) (a)%(b)==0?(a)/(b):(a)/(b)+1

 int N,K;
int A[200100];

bool check(int block){
    int p = 0;
    for(int i=0; i<N; i++){
        p += CEIL(A[i], block) - 1;
        if(p>K){
            return false;
        }
    }
    return true;
}

int main(){
    cin >> N >> K;
    int m=0;
    for(int i=0; i<N; i++){
        cin >> A[i];
        if(m<A[i]){
            m = A[i];
        }
    }
    int l = CEIL(m,K);
    m++;
    while(l+1<m){
        int mid = (l+m) / 2;
        if(check(mid)){
            m = mid;
        } else {
            l = mid;
        }
    }
    cout << m << endl;
    return 0;
}