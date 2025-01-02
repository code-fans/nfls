#include <bits/stdc++.h>
using namespace std;
queue<int> qq;
queue<int> q[1010];
unordered_map<int ,int > ren;
int main()
{
    int n, r;
    cin>>n;
    int n1;
    for (int i = 0; i < n; i++){
        cin>>n1;
        for (int j = 0; j < n1; j++){
            cin >> r;
            ren[r] = i;
        }
    }
    string str;
    while (1){
        cin>>str;
        if(str=="STOP")
            break;
        if(str=="ENQUEUE"){
            cin>>r;
            q[ren[r]].push(r);
            if(q[ren[r]].size()==1){
                qq.push(ren[r]);
            }
        }else{
            n=qq.front();
            cout<<q[n].front()<<endl;
            q[n].pop();
            if(q[n].size()==0){
                qq.pop();
            }
        }
    }
    return 0; 
}