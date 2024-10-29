#include <bits/stdc++.h>
using namespace std;

int n,A1,k;
int A[10000100];

int main(){
    long long p = 1000000007;
    cin >> n >> A1 >> k;
    A1 %= p;
    A[0]=A1;
    for(int i=1; i<n; i++){
        long long temp = A[i-1];
        temp = temp * temp % p;
        A[i] = temp;
    }
    nth_element(A, A+k-1, A+n, greater<int>());
    cout << A[k-1]  << endl;
    return 0;
}
