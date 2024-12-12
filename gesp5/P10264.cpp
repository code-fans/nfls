#include <iostream>
#include <cstring>
#include <map>
#include <utility>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

    int T,N,M, t;
    cin >>T;
    while(T--){
        cin >> N;
        int nextPos[15100] = {0};
        int lastCard[15] = {0};
        for(int i=1; i<=N; i++){
            cin >> t;
            if(lastCard[t] > 0){
                nextPos[lastCard[t]] = i;
            }
            lastCard[t] = i;
        }
        cin >> M;
        while(M--){
            int b,e, ans = 0;
            map< <pair<int,int> , int > quest;
            cin >> b >> e;
            if(quest.count({b,e})>0){
                ans = quest[{b,e}];
            } else {
                while(b<=e){
                    if(nextPos[b]>0 && nextPos[b]<=e){
                        b = nextPos[b];
                    } else {
                        ans ++;
                    }
                    b++;
                }
                quest[{b,e}] = ans;
            }
            cout << ans << endl;
        }
    }
    return 0;
}