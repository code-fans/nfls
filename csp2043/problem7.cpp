#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("divide.in","r",stdin);
    freopen("divide.out","w",stdout);
    string str,str1,str2;
    int n,len;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>len;
        cin>>str;
        bool notcan=true;
        for (int j = 1; j < len; j++){
            str1=str.substr(0,j);
            str2=str.substr(j,len-j);
            if(str1<str2){
                notcan=false;
                break;
            }
        }
        if(notcan)
            cout<<"No"<<endl;
        else
            cout<<"Yes"<<endl;
    }
    return 0;
}