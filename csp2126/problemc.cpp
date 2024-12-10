#include <bits/stdc++.h>
using namespace std;
int main()
{
    int R,D,S,a[15];
    cin>>R>>D>>S;
    for (int i = 0; i < D; i++){
        int num,num1;
        cin>>num>>num1;
        a[num] |=1<<num1;
        a[num1] |=1<<num;
    }
    for (int i = 0; i < S; i++){
        int num,num1;
        cin>>num>>num1;
        a[num] |=1<<(num1+10);
    }
    
    set<pair<int ,int >> foot;
    const pair<int ,int > e = {R,1<<R};
    queue<tuple<int,int,int>> qu;
    qu.push({1,1<<1,0});
    foot.insert({1,1<<1});
    while(!qu.empty()){
        tuple<int,int ,int > st=qu.front();
        qu.pop();
        const int r=get<0>(st);
        int s = get<1>(st);
        for (int j = 1; j <= R; j++){
            if(a[r]&1<<(j+10)){
                int ss = s^(1<<j);
                pair<int ,int > nextSt={r,ss};
                if(nextSt == e){
                    cout<<"Mr. Black needs "<<get<2>(st)+1<<" steps.\n";
                    return 0;
                }
                if(foot.count(nextSt)==0){
                    qu.push({r,ss,get<2>(st)+1});
                    foot.insert(nextSt);
                }
            }
        }
        for (int j = 1; j <= R; j++){
            if(a[r]&1<<j && s&1<<j){
                pair<int ,int > nextSt={j,s};
                if(foot.count(nextSt)==0){
                    qu.push({j,s,get<2>(st)+1});
                    foot.insert(nextSt);
                }
            }
        }
    }
    cout<<"Poor Mr. Black! No sleep tonight!"<<endl;
    return 0;
}