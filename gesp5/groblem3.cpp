#include <iostream>
using namespace std;

void brain(long long n){
    if(n%2==1){
        cout <<"-1";
    }
    if(n == 0){
        return;
    }
    long long p = n & (-n);
    brain(n-p);
    cout << p <<' ';
}

int main()
{
    long long n;
    cin>>n;
    brain(n);
    cout<<endl;
    return 0;
}