#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("../csp2110/input.in","r",stdin);
    int k,n,a[100100],b;
    cin>>k;
    for (int i = 0; i < k; i++){
        int r=0,sk[100100];
        cin>>n;
        for (int j = 0; j < n; j++){
            cin>>a[j];
        }
        bool ans = true;
        int m=0;
        for (int j = 0; j < n ; j++){
            cin>>b;
            while((r==0 || sk[r-1]!=b) && m<n){
                sk[r]=a[m];
                r++;
                m++;
            } 
            if(b==sk[r-1]){
                r--;
            } else {
                ans = false;
            }
        }

        if(ans){
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    
    return 0;
}