#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    long long num;
    for (int i = 0; i < n; i++){
        cin>>num;
        long long jz=num/10%10;
        if(jz>=5)
            cout<<num/100*100+100<<endl;
        else
            cout<<num/100*100<<endl;
    }
    return 0;
}