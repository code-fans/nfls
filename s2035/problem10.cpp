#include <iostream>
using namespace std;
int main()
{
    freopen("iq.in","r",stdin);
    freopen("iq.out","w",stdout);
    int n,a[100000];
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    if(n<=2){
        if(n==2&&a[0]==a[1]){
            cout<<a[0]<<endl;
            return 0;
        }
        cout<<"AMBIGUITY"<<endl;
        return 0;
    }
    if(a[0]==a[1]){
        for(int i=2;i<n;i++)
            if (a[i]!=a[0]){
                cout<<"BUG"<<endl;
                return 0;
            }
        cout<<a[0]<<endl;
        return 0;
    }
    //a[2] = a[1] * x + y;
    //a[1] = a[0] * x + y;
    //a[2] - a[1] = (a[1] - a[0]) * x;
    int x = (a[2] - a[1]) / (a[1] - a[0]);
    int y = a[2] - a[1] * x;
    for (int i = 1; i < n; i++){
        if(a[i]!=a[i-1]*x+y){
            cout<<"BUG"<<endl;
            return 0;
        }
    }
    cout<<a[n-1]*x+y<<endl;    
    return 0;
}