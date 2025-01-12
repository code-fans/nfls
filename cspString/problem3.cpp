#include <iostream>
#include <string>
using namespace std;
int bida(char a) {
    if (a == '(')
        return 4;
    if (a == '*' || a == '/')
        return 3;
    if (a == '+' || a == '-')
        return 2;
    return 1;
}


char b[10000];

int main() {
    
    int sizea = 0, sizeb = 0;
    
    string str;
    cin >> str;
    str.push_back(')');
    string num = "";
    int ismun = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            num += str[i];
            ismun = 1;
        } else {
            if (ismun) {
                cout << num << ' ';
                ismun = 0;
                num = "";
            }
            while (sizeb >= 1 && bida(str[i]) <= bida(b[sizeb - 1]) && b[sizeb - 1] != '(') {
                cout<< b[sizeb - 1]<<' ';
                sizeb--;
            }
            if (sizeb > 0 && b[sizeb - 1] == '(' && str[i] == ')')
                sizeb--;
            else {
                b[sizeb] = str[i];
                sizeb++;
            }
        }
    }
    cout<<endl;
    return 0;
}