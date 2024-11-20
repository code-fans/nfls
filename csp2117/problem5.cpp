#include <iostream>
using namespace std;

int splitChocolate(int l, int w, int d){
    if(d > l*w/2) d = l*w - d;
    if(d==0) return 0;
    int ans = 1e9, tmp;
    int l1 = d/w;
    
    if(l1>0){
        tmp = w*w + splitChocolate(l-l1, w, d-l1*w);
        if(tmp<ans) ans = tmp;
    }
    if(l>l1+1 && d>l1*w){
        tmp = w*w + splitChocolate(l1+1, w, d);
        if(tmp<ans) ans = tmp;
    }
    int w1 = d/l;
    if(w1>0){
        tmp = l*l+ splitChocolate(l, w-w1, d-l*w1);
        if(tmp<ans) ans = tmp;
    }
    if(w>w1+1 && d>w1*l){
        tmp = l*l+ splitChocolate(l, w1+1, d);
        if(tmp<ans) ans = tmp;
    }

    return ans;
}

int main(){
    int n, a,b,c;
    cin>>n;
    while(n--){
        cin >> a >> b >> c;
        cout << splitChocolate(a,b,c) << endl;
    }
    return 0;
}