#include <iostream>
#include <algorithm>

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
    int a[] = {1,1,3,3,3,4,5,6,7,7,8,9,10,12,15};
    int v;
    cout << "{1,1,3,3,3,4,5,6,7,7,8,9,10,12,15}" << endl;
    cin >> v;
    while(v>=0){
        int l3 = lb(a, 15, v);
        int l32 = lower_bound(a, a+15, v) - a;
        int u3 = ub(a, 15, v);
        int u32 = upper_bound(a, a+15, v) - a;
        cout<< "lower: "<<l3 <<" - "<< l32 << " upper: "<<u3 <<" - "<< u32 << endl;
        cin >> v;
    }
    return 0;
}
