#include <iostream>
using namespace std;
int pn[20000000];
int n=0;
int maxn = 100000000;

bool isprime(int p){
    for(int i=0; i<n && pn[i]*pn[i]<=p; i++){
        if(p%pn[i]==0)
            return false;
    }
    return true;
}
int main(){
    pn[0] = 2;
    n=1;
    int p6=0,p7=0,p8=0;
    for(int i=3;i<maxn; i+=2){
        if(isprime(i)){
            pn[n]=i;
            n++;
        
            if(p6==0 && i>1e5 ){
                p6 = n;
            }
            if(p7==0 && i>1e6 ){
                p7 = n;
            }
            if(p8==0 && i>1e7 ){
                p8 = n;
            }
        }
    }
    int p1=0;
    while(pn[p1]<200){
        if(p1>0 && p1%10==0) cout << endl;
        cout << pn[p1] << ' ';
        p1++;
    }
    cout << endl;
    for(int i=0; i<10; i++){
        cout << pn[p6+i] << ' ';
    }
    cout << endl;
    for(int i=0; i<10; i++){
        cout << pn[p7+i] << ' ';
    }
    cout << endl;
    for(int i=0; i<10; i++){
        cout << pn[p8+i] << ' ';
    }
    cout << endl;
    return 0;
}