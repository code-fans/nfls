 #include <iostream>
 using namespace std;
 int main()
 {
    long long ans=1,n;
    cin>>n;
    while(n>=ans){
        ans <<=1;
    }
    cout<< ans/2 <<endl;
    return 0;
 }