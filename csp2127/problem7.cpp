#include <bits/stdc++.h>
using namespace std;

map<int, int> contrys;
queue<pair<int, vector<int> > > shipMan;
int ans = 0;

int main(){
    
    int n, t, m, x;
    cin >> n;
    while(n--){
        cin >> t >> m;
        vector<int> mans;
        while(m--){
            cin >> x;
            mans.push_back(x);
            contrys[x] ++;
            if(contrys[x]==1){
                ans ++;
            }
        }
        shipMan.push({t, mans});
        while(shipMan.front().first <= t - 86400){
            for(int n : shipMan.front().second){
                contrys[n] --;
                if(contrys[n]==0){
                    ans --;
                }
            }
            shipMan.pop();
        }
        cout << ans << endl;
    }

    return 0;
}