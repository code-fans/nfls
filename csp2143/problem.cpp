#include <iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long a,b,c,ans;
    while(n--){
        cin>>a>>b;
        c=1;
        ans=0;
        for(int i=0;i<63;i++, c=c<<1){
            if(a&c){
                ans++;
            }else{
                if(a+c<=b){
                    ans++;
                    a|=c;
                }
            }
        }
        cout<<ans<<endl;
    } 
    return 0;
}
/*
1
1 9223372036854775807
*/