#include <bits/stdc++.h>

using namespace std;
int main(){
    int n ;
    string w;
    set<string> words;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> w;
        words.insert(w);
    }

    int ans=0;
    while(cin >> w){
        if(words.count(w)<=0){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
