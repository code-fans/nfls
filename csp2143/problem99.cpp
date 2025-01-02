#include <bits/stdc++.h>
using namespace std;
char sk[1000000],n;
int sizea=0;
int main()
{
    int ans=0;
    while (cin>>n){
        if(n=='<'||n=='('||n=='{'||n=='['){
            sk[sizea]=n;
            sizea++;
        }else{
            if(!((sk[sizea-1]=='<'&&n=='>')||(sk[sizea-1]=='('&&n==')')||(sk[sizea-1]=='{'&&n=='}')||(sk[sizea-1]=='['&&n==']')))
                ans++;
            if(sizea==0){
                cout<<"Impossible"<<endl;
                return 0;
            }
            sizea--;
        }
    }
    if(sizea!=0)
        cout<<"Impossible"<<endl;
    else
        cout<<ans<<endl;
    return 0;
}