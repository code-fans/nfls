#include <iostream>
#include <queue>
#include <set>
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
    int b = (1 << 16) + (1 << 1);
    const int e = (R << 16) + (1<<R);
    int step = 1;
    queue <pair<int, int> > qu;
    set<int> foot;
    qu.push({b, 0});
    foot.insert(b);

    while(!qu.empty()){
        pair<int, int> st = qu.front();
        int c = st.first;
        qu.pop();
        const int r = c >> 16;
        int s = c & ((1<<16)-1);
        for(int i=0; i<S; i++){
            if(kg[i][0] == r){
                int next = (r << 16) + (s ^ (1 << kg[i][1]));
                if(next == e){
                    cout << "Mr. Black needs " << step << " steps."<< endl;
                    return 0;
                }
            
                if(foot.count(next) == 0){
                    qu.push({next, st.second+1});
                    foot.insert(next);
                }
            }
        }

        for(int i=0; i<D; i++){
            if(edge[i][0] == r){
                int next = (edge[i][1] << 16)+ s;
                if(foot.count(next) == 0){
                    qu.push({next, st.second+1});
                    foot.insert(next);
                }
            }

            if(edge[i][1] == r){
                int next = (edge[i][0] << 16)+ s;
                if(foot.count(next) == 0){
                    qu.push({next, st.second+1});
                    foot.insert(next);
                }
            }
        }

    }
    cout << "Poor Mr. Black! No sleep tonight!" << endl;
    return 0;
}