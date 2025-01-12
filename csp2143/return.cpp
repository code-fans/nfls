#include <bits/stdc++.h>
using namespace std;
char a[2000000];
int sizea=0;
int main(){
    long long ans=2;
    long long n;
    cin>>n>>ans;
    char b;
    for (int i = 0; i < n; i++){
        cin>>b;
        if(b=='U' && sizea!=0&&(a[sizea-1]!='U')){
            sizea--;
        }else{
            a[sizea]=b;
            sizea++;
        }
    }

    for (int i = 0; i < sizea; i++){
        if(a[i]=='U'&&ans!=1){
            ans/=2;
        } else
        if(a[i]=='L'){
            ans*=2;
        } else 
        if(a[i]=='R'){
            ans*=2;
            ans+=1;
        }
    }
    cout<<ans<<endl;
    return 0;
}