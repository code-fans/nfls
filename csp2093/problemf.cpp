#include <iostream>
#include <algorithm>

using namespace std;
int a[300000], b[300000] ;
int N,M,K;
bool check(int v){
    int d=0;
    for(int i=0;i<N && a[i]<v;i++){
        d+= upper_bound(b, b+M, v - a[i]) - b;
        if(d>=K) return true;
    }
    return false;
}

int main()
{
    
    cin>>N>>M>>K;
    for (int i = 0; i < N; i++){
        cin>>a[i];
    }
    for (int i = 0; i < M; i++){
        cin>>b[i];
    }
    int l=0, r=2e8+1;
    while (l+1<r){
        int mid=(l+r)/2;
        if(check(mid))
            r=mid;
        else
            l=mid;
    }
    cout<<r<<endl;
    return 0;
}