#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> timeMap;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, t, m, x;
    cin >> n;
    while(n--){
        cin >> t >> m;
        while(m--){
            cin >> x;
            timeMap[x] = t;
        }
        int ans = 0;
        for(auto p : timeMap){
            if(p.second > t-86400){
                ans ++;
            }
        }
        cout << ans << endl;
    }

    return 0;
}