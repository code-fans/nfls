#include <iostream>
using namespace std;

int main(){
    long long n,a[1000000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    long long h=0,w=0;
    long long ans=0,k=1;
    for (int i = 0; i < 31; i++){
        h=0;
        w=0;
        for (int j = 0; j < n; j++){
            if(a[j]%2)
                w++;
            else
                h++;
            a[j]/=2;
        }
        ans+=w*h*k;
        k*=2;
    }
    cout<<ans<<endl;
    return 0;
}