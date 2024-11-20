#include <iostream>
#include <queue>
#include <stack>
using namespace std;
int main()
{
    int n;
    int d=0,f=0,sizes=0;
    char a;
    while (cin>>n){
        queue<char> qa;
        for(int i=0;i<n;i++){
            cin>>a;
            qa.push(a);
        }
        stack<char> sa;
        while (!qa.empty()){
            a = qa.front();
            qa.pop();
            if(sa.empty() || sa.top()==a){
                sa.push(a);
            } else {
                qa.push(sa.top());
                sa.pop();
            }
        }
        cout<<sa.top()<<endl;
    }
    return 0;
}