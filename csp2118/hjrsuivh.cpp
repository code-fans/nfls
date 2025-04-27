#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,h;
    cin>>h>>n;
    for (int i = 0; i < n; i++){
        long long m;
        cin>>m;
        for (int j = 1; 1 ; j++){
            if(j*j==m&&j*j>h){
                cout<<"lucky"<<endl;
                break;
            }
            if(m%(j*j)==0&&j*j>h){
                cout<<j*j<<endl;
                break;
            }
            
        }
    }
    return 0;
}