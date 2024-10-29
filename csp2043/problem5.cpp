#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    double n[10000]={0};
    int sizef=0,sizen=0;
    string a;
    //freopen("../csp2043/input.txt", "r", stdin);
    while (cin>>a){
        if(a[0]>='0'&&a[0]<='9'){
            n[sizen]=0;
            for(int i=0;i<a.size();i++){
                n[sizen]*=10;
                n[sizen]+=a[i]-'0';
            }
            sizen++;
        }else if(a=="+"){
            n[sizen-2]+=n[sizen-1];
            sizen--;
        } else if(a=="-"){
            n[sizen-2]-=n[sizen-1];
            sizen--;
        } else if(a=="/"){
            n[sizen-2]/=n[sizen-1];
            sizen--;
        } else if(a=="*"){
            n[sizen-2]*=n[sizen-1];
            sizen--;
        }
    }
    printf("%.3f\n",n[0]);
    return 0;
}