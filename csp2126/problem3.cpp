#include <iostream>
#include <queue>
#include <set>
#include <tuple>
#include <utility>
using namespace std;

int edge[128][2];
int kg[128][2];
int main(){
    int R, D , S;
    cin >> R >> D >> S;
    for(int i=0; i<D; i++){
        cin >> edge[i][0] >> edge[i][1];
    }
    for(int i=0; i<S; i++){
        cin >> kg[i][0] >> kg[i][1];
    }
    pair<int, int> b = {1, 1<<1 };
    const pair<int, int> e = {R , 1 << R};
    queue< tuple  <int, int, int > > qu;
    set<pair<int, int>> foot;
    qu.push({1 , 1<<1, 0});
    foot.insert(b);
    while(!qu.empty()){
        tuple<int, int, int> st = qu.front();
        qu.pop();
        const int r = get<0>(st);
        int s = get<1>(st);
        for(int i=0; i<S; i++){
            if(kg[i][0] == r){
                pair<int, int> nextSt = { r, s ^ (1 << kg[i][1]) };
                if(nextSt == e){
                    cout << "Mr. Black needs " << get<2>(st)+1 << " steps."<< endl;
                    return 0;
                }
                if(foot.count(nextSt) == 0){
                    qu.push({r, nextSt.second, get<2>(st)+1});
                    foot.insert(nextSt);
                }
            }
        }
        for(int i=0; i<D; i++){
            if(edge[i][0] == r && (s & (1<<edge[i][1]))){
                pair<int, int> nextSt ={ edge[i][1], s};
                if(foot.count(nextSt) == 0){
                    qu.push({edge[i][1], s, get<2>(st)+1});
                    foot.insert(nextSt);
                }
            }
            if(edge[i][1] == r  && (s & (1<<edge[i][0]))){
               pair<int, int> nextSt ={ edge[i][0], s};
                if(foot.count(nextSt) == 0){
                    qu.push({edge[i][0], s, get<2>(st)+1});
                    foot.insert(nextSt);
                }
            }
        }
    }

    cout << "Poor Mr. Black! No sleep tonight!" << endl;
    return 0;
}