#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
int h, w;
int p[10][10007];
int cnt[100007];
int main() {
    long long ans=0;
    cin >> h >> w;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> p[i][j];
        }
    }
    
    for (int st = 1; st < 1<<h; st++){
        int col[10]={0};
        long long h1=0,w1=0;
        for (int j = 0; j < h; j++){
            if(st & (1<<j)){ // st >> j & 1
                //cout<<j<<endl;
                col[h1]=j;
                h1++;
            }
        }
        unordered_map<int, int> mp;
        for(int i=0; i<w; i++){
            int t = p[col[0]][i];
            bool yz = true;
            for(int j=1; j<h1; j++){
                if(p[col[j]][i]!=t){
                    yz=false;
                    break;
                }
            }
            if(yz){
                mp[t]++;
                if(w1<mp[t])
                    w1=mp[t];
            }
        }
        ans=max(ans,h1*w1);
    }
    cout<<ans<<endl;
    return 0;
}