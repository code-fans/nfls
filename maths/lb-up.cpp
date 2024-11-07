#include <iostream>
using namespace std;

int lb(int ar[], int len, int v){
    int l=0, r=len;
    while(l<r){
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
    int l=0, r=len;
    while(l<r){
        int mid = (l+r) / 2;
        if(ar[mid] <= v){
            l = mid;
        } else {
            r = mid;
        }
    }    
    return r;
}

int main(){
    int a[] = {1,2,3,3,3,3,4,5,6,7,7,8,9,10};
    int l3 = lb(a, 15, 3);
    int u3 = ub(a, 15, 3);
    cout<< l3 <<' '<< u3 << endl;
    return 0;
}
