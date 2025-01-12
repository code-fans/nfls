#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;


int main(){
    freopen("../csp2154/input.txt", "r", stdin);
    string str;
    while(true){
        getline(cin, str);
        if(str.empty()) break;
        stringstream ss(str);
        char a;
        while(ss >> a){
            cout << a << ' ';
        }
        cout << endl;
    }
    return 0;
}