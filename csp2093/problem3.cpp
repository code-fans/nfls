#include <bits/stdc++.h>
using namespace std;

#define CEIL(a,b)  ( (a)%(b)==0?(a)/(b):(a)/(b)+1 )

int n, a, b , c;
int h[100100];

bool check(int days){
    int td = 0;
    int ps = days * b;
    for(int i=0; i<n; i++){
        if(h[i] > ps){
            td += CEIL(h[i]-ps, c);
            if(td>days)
                return false;
        }
    }
    return true;
}

int main(){
    cin >> n >> a >>b;
    int m = 0;
    for(int i=0; i<n; i++){
        cin >> h[i];
        if(m<h[i]){
            m = h[i];
        }
    }
    c = a-b;
    int l =  CEIL(m, a)-1;
    m = CEIL(m, b) +1;
    while(l+1<m){
        int mid = (l+m) / 2;
        if(check(mid)){
            m = mid;
        } else {
            l = mid;
        }
    }
    cout << m << endl;
    return 0;
}