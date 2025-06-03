#include <bits/stdc++.h>
using namespace std;
int n, g, ans=1;
map<int, int> pc;

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>g;
        for(int j=2; j*j <= g; j++){
            if(g%j ==0){
                pc[j] ++;
                if(pc[j]>ans) ans = pc[j];
                do{
                    g /= j;
                }while(g%j==0);
            }
        }
        if(g>1){
            pc[g] ++;
            if(pc[g]>ans) ans = pc[g];
        }
    }
    if(ans == 1)
        cout<<"pairwise coprime"<<endl;
    else if(ans < n)
        cout<<"setwise coprime"<<endl;
    else
        cout<<"not coprime"<<endl;
    return 0;
}