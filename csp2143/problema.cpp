#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string, int> m;
    int n;
    string str;
    set<string> ans1;
    cin>>n;
    int ans=0;
    for (int i = 0; i < n; i++){
        cin>>str;
        m[str]++;
        if(m[str]==ans){
            ans1.insert(str);
        }else if(m[str]>ans){
            ans=m[str];
            ans1.clear();
            ans1.insert(str);
        }
    }
    for (auto & s : ans1){
        cout<<s<<endl;
    }
    
    return 0;
}