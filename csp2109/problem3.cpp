#include <iostream>
#include <unordered_map>
using namespace std;
unordered_map<int, int> a;
int main()
{
    int n,k,b,ans=0;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>b;
        if(a.count(b)>0 && a[b] >= i-k){
            if(b>ans) ans = b;
        }
        a[b]=i;
    }
    cout<<ans<<endl;
    return 0;
}