#include <bits/stdc++.h>
using namespace std;
int a[200200][2];

void qx(int i){
    if(i == 0) return;
    cout << i << ' ';
    qx(a[i][0]);
    qx(a[i][1]);
}

void zx(int i){
    if(i == 0) return;
    zx(a[i][0]);
    cout << i << ' ';
    zx(a[i][1]);
}

void hx(int i){
    if(i == 0) return;
    hx(a[i][0]);
    hx(a[i][1]);
    cout << i << ' ';
}

int main()
{
    int n;
    cin>>n;
    for(int i=1; i<=n; i++){
        cin >> a[i][0] >> a[i][1];
    }
    qx(1);
    cout << endl;
    zx(1);
    cout << endl;
    hx(1);
    cout << endl;
    return 0;
}

