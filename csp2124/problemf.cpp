#include <iostream>
#include <map>
using namespace std;
long long N, A[2500], K;
map<long long, int> one;
map<long long, int> two;
long long gcm(long long a, long long b){
    while(a%b !=0){
        long long r = a%b;
        a = b;
        b = r;
    }
    return b;
}
int main(){
    cin >> N ;
    for(int i=0; i<N; i++){
        cin >> A[i];
    }
    cin >> K;
    long long ans =0;
    for(int i=0; i<N; i++){
        long long r = gcm(A[i], K);
        for(const auto& pair : two){
            if( (pair.first * r) % K == 0){
                ans += pair.second;
            }
        }
        for(const auto& pair : one){
            long long r2 = gcm(pair.first * r, K);
            two[r2] += pair.second;
        }
        one[r]++;
    }
    cout << ans << endl;
    return 0;
}