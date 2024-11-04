#include <iostream>
using namespace std;
int main()
{
    int a[4][2],c=0;
    for (int i = 0; i < 4; i++){
        cin>>a[i][0]>>a[i][1];
        for( int j = 0;j < i; j++)
            c+=(a[j][0]-a[i][0])*(a[j][0]-a[i][0])+(a[j][1]-a[i][1])*(a[j][1]-a[i][1]);
    }
    if(c==20)
        cout<<"zhisi"<<endl;
    if(c==14)
        cout<<"qusi"<<endl;
    if(c==12)
        cout<<"wansi"<<endl;
    if(c==11)
        cout<<"dingsi"<<endl;
    if(c==8)
        cout<<"fangsi"<<endl;
    return 0;
}