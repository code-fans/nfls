#include <iostream>
#include <algorithm>
#include <bitset>

using namespace std;

int main(){
    int n [] = {12,11,10,8,9,6,7,5,4,1,2,3};
    bitset<16> bitstr =  bitset<16>(-1);
    cout << bitstr.to_string() << endl;
    /*sort(n, n+12, less<int>());
    int a[4];
    int ans = 1e9;
    do{
        a[0] = n[0]+n[1]+n[2];
        a[1] = n[3]+n[4]+n[5];
        a[2] = n[6]+n[7]+n[8];
        a[3] = n[9]+n[10]+n[11];
        sort(a, a+4);
        if(a[3]-a[0]< ans) ans = a[3]-a[0];

    }while (next_permutation(n, n+12));
    cout << ans << endl;
    */
    return 0;
}