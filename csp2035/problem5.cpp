#include <bits/stdc++.h>
#include <set>
using namespace std;

set<int> s[26][26];
int main(){

    cout << (s[0][0].find(1) != s[0][0].end())  << endl;
    s[0][0].insert(1);
    cout << (s[0][0].find(1) != s[0][0].end())  << endl;
    return 0;
}
