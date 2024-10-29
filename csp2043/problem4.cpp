#include <iostream>
using namespace std;
int n,m,a[1010][1100]={{0}},b[2][1010],ans=0;
int main()
{
    cin>>n>>m;
    for (int i = 1; i <= m; i++){
        cin>>b[0][i]>>b[1][i];
    }
    for (int i = 1; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if( j>=b[0][i] && a[i-1][j] < (b[1][i]+ a[i-1] [j-b[0][i]]) ){
                a[i][j] = b[1][i]+a[i-1][j-b[0][i]];
            } else {
                a[i][j] = a[i-1][j];
            }
        }
    }
    cout<<a[m][n]<<endl;
    return 0;
}