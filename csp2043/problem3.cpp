#include <iostream>
using namespace std;
int W[40];
int Bag(int s,int n)
{
    if(s==0)
        return 1;
    if(s<0 || (s> 0&& n<1))
        return 0;
    if (Bag(s-W[n],n-1))
    {
        cout<<W[n]<<endl;
        return 1;
    }
    return Bag(s,n-1);
}
int main()
{
    int S,N;
    cin>>S>>N;
    for(int i=1;i<=N;++i)
        cin>>W[i];
    if(!Bag(S,N))
        cout<<"Failed!"<<endl;
    return 0;
}