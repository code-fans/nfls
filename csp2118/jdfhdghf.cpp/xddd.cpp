#include <bits/stdc++.h>
using namespace std; 
int main()
{
    int n;
    cin>>n;
    for(int i=0;i*i * 4 <= n;i++)
        for (int j = i; j*j *3 <= n-i*i; j++)
            for (int k = j; k*k* 2 <= n-i*i-j*j; k++){
                int num=sqrt(n-i*i-j*j-k*k)+0.0001;
                if(num*num==n-i*i-j*j-k*k){
                    cout<<i<<' '<<j<<' '<<k<<' '<<num<<endl;
                    return 0;
                }
            }
    return 0;
}