#include <iostream>
using namespace std;
int main()
{
    int n;
    long long k;
    long long b[100000]={0},a;
    cin>>n>>k;
    for (int i = 1; i <= n; i++){
        cin>>a;
        b[i]=b[i-1]+a;
    }
    int l=0,r=0;
    long long ans = 0;
    while (r<=n){
        while(r<=n && b[r] - b[l] < k ) r++;
        ans += n-r+1;
        l++;
    }
    cout<<ans<<endl;
    return 0;
}