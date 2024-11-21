#include <iostream>
#include <algorithm>
using namespace std;
int n,st[300000], a[300000];
int main()
{
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>a[i];
    }
    int l=1;
    st[0] = -1e9;
    for (int i = 0; i < n; i++){
        int p = lower_bound(st, st+l, a[i]) - st;
        if(p<=1){
            cout << "0 ";
        } else {
            cout << st[p-1]<<' ';
        }
        while(l>0 && st[l-1]>= a[i] ) l--;
        st[l] = a[i];
        l++;
    }
    cout<< endl;
    return 0;
}