#include <bits/stdc++.h>
using namespace std;
int main()
{
    priority_queue<int, vector<int> , greater<int>> qu;
    queue<int> ar;
    int st,w,N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin>>st;
        if(st==1){
            cin>>w;
            ar.push(w);
        }else if(st==2){
            if(qu.empty()){
                cout << ar.front()<< endl;
                ar.pop();
            } else {
                cout<<qu.top()<< endl;
                qu.pop();
            }
        }else{
            while (!ar.empty()){
                qu.push(ar.front());
                ar.pop();
            }
        }
    }
    return 0;
}