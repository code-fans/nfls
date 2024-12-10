#include <iostream>
#include <map>
using namespace std;
map<int,int> timeMap;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, t, m, x;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>t>>m;
        for (int j = 0; j < m; j++){
            cin>>x;
            timeMap[x] = t;
        }
        int ans=0;
        for(const auto & p : timeMap){
            if(p.second>t-86400){
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}