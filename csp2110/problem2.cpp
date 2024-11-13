#include <iostream>
using namespace std;
int main()
{
    char a[100000],d;
    int ans=0,k=0,sizes=0;
    //freopen("../csp2110/input.in","r",stdin);
    while (cin>>d){
        if(d=='('||d=='['||d=='{'){
            a[sizes]=d;
            sizes++;
        } else {
            if(sizes&&((d==')'&&a[sizes-1]=='(')||(d==']'&&a[sizes-1]== '[')||(d=='}'&&a[sizes-1]=='{'))){
                sizes--;
                k+=2;
            } else {
                sizes=0;
                k=0;
            }
        }
        if(k>ans)
                ans=k;
    }
    cout<<ans<<endl;
    return 0;
}