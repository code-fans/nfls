#include <bits/stdc++.h>
using namespace std;
int a[100000000];
int main()
{
    long long num;
    cin>>num;
    for (int i = 0; i*i <= num; i++){
        a[i*i]=1;
        for (int j = 0; j <= num; j++){
            if(a[j]!=0){
                if(a[j+i*i]==0){
                    a[j+i*i]=a[j]+1;
                }else{
                    a[j+i*i]=min(a[j]+1,a[j+i*i]);
                }
            }
        }
        
    }
    cout<<a[num]<<endl;
    return 0;
}