#include <bits/stdc++.h>
using namespace std;
string num[5][4] = {
    { ".....", "****.", ".....", "....."},
    { ".***.", "****.", "****.", "****."},
    { ".***.", "****.", ".....", "....."},
    { ".***.", "****.", ".****", "****."},
    { ".....", "****.", ".....", "....."}
};

int main()
{
    string a;
    cin>>a;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < a.size(); j++){
            cout << num[i][a[j]-'0'];
        }
        cout<<endl;
    }
   
    
    return 0;
}