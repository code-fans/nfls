#include <iostream>
#include <sstream>
#include <cstring>

using namespace std;
bool formula(stringstream & ss);
int a[256];
bool item(stringstream & ss){
    char c;
    ss >> c;
    if(c=='V') return true;
    if(c=='F') return false;
    if(c=='!'){
        return ! item(ss);
    }
    if(c=='('){
        return formula(ss);
    }
    return false;
}

bool formula(stringstream & ss){
    //formula 我只考虑 & | 这两个二元操作 ： 要考虑 & 优先与 |
    bool datastack[10]; int dss=0,oss=0;
    char opstack[10];
    datastack[dss++]= item(ss);
    char op;
    while(ss >> op){
        if(op =='&' || op=='|'){
            //弹出栈中的内容
            while(oss>0 && a[opstack[oss-1]] >= a[op]){
                oss--;
                dss--;
                if( opstack[oss] == '&')
                    datastack[dss-1] =  datastack[dss-1] && datastack[dss];
                else
                    datastack[dss-1] =  datastack[dss-1] || datastack[dss];
            }
            opstack[oss++]=op;
            datastack[dss++]= item(ss);
        } else break;
    }
    while(oss>0){
        oss--;
        dss--;
        if( opstack[oss] == '&')
            datastack[dss-1] =  datastack[dss-1] && datastack[dss];
        else
            datastack[dss-1] =  datastack[dss-1] || datastack[dss];
    }
    //弹出栈中的内容
    return datastack[0]; // 返回数据栈顶
}

int main(){
    a['&'] = 2;
    a['|'] = 1;
    freopen("../csp2154/input.txt", "r", stdin);
    while(true){
        string str;
        getline(cin, str);
        if(str.empty()) break;
        stringstream ss(str);
        cout << (formula(ss)?'V':'F') << endl;
    }
    return 0;
}
