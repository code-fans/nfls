#include <iostream>
#include <string>
using namespace std;
int main()
{
    freopen("imena.in","r",stdin);
    freopen("imena.out","w",stdout);
    int i=0,n,ans=0;
    cin>>n;
    string str;
    while (i<n){
        cin>>str;
        int p=1;
        if(str[0]<'A'||str[0]>'Z')
            p=0;
        for (int j = 1; j < str.size(); j++){
            if(str[j]=='.'||str[j]=='!'||str[j]=='?'){
                i++;
                ans+=p;
                cout<<ans<<endl;
                ans=0;
                p=0;
            } else if(!(str[j]>='a'&&str[j]<='z'))
                p=0;
        }
        ans+=p;
    }
    return 0;
}