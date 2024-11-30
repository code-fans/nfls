#include <bits/stdc++.h>
using namespace std;
unordered_set<string> htab;
int main()
{
    int n;
    string str;
    cin>>n;
    for (int i = 1; i <= n; i++){
        cin>>str;
        if(htab.count(str)==0){
            htab.insert(str);
            cout<<i<<endl;
        }
    }
    return 0;
}