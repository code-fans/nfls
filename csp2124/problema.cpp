#include <bits/stdc++.h>
using namespace std;
long long zhong,n,ans[100000],zh[100000],jia[100000];
int main()
{
    cin>>zhong>>n;
    for (int i = 0; i < n; i++){
        cin>>zh[i]>>jia[i];
    }
    for (int i = 0; i < n; i++){
        for(int j=0;j<=zhong-zh[i];j++){
            if(ans[j+zh[i]]<ans[j]+jia[i]){
                ans[j+zh[i]]=ans[j]+jia[i];
            }
        }
    }
    long long coutans=0;
    for(int i=0;i<=zhong;i++){
        if(coutans<ans[i])
            coutans=ans[i];
    }
    cout<<coutans<<endl;
    return 0;
}