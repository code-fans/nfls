#include <iostream>
using namespace std;

int lb(int ar[], int len, int v){
    int l=-1, r=len;
    while(l<r-1){
        int mid = (l+r) / 2;
        if(ar[mid] >= v){
            r = mid;
        } else {
            l = mid;
        }
    }    
    return r;
}

int ub(int ar[], int len, int v){
    int l=-1, r=len;
    while(l<r-1){
        int mid = (l+r) / 2;
        if(ar[mid] > v){
            r = mid;
        } else {
            l = mid;
        }
    }    
    return r;
}

int main(){
    int v;
    cin >> v;
    int a[] = {1,1,3,3,3,4,5,6,7,7,8,9,10,12,15};
    int l3 = lb(a, 15, v);
    int u3 = ub(a, 15, v);
    cout<< l3 <<' '<< u3 << endl;
    return 0;
}
