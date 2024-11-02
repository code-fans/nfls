#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> numPos;
int main()
{
    numPos.reserve(3e5);
    int l=0,n,m,ans=0,c=0,n1;
    cin>>n;
    for (int i = 1; i <= n; i++){
        cin>>n1;
        for(int j = 0;j<n1;j++){
            cin>>m;
            int  b=numPos[m];
            if(b==0){
                cout<<m<<' ';
                numPos[m] = i;
            }
        }
        cout<<endl;
        numPos.clear();
    }
    return 0;
}