#include <iostream>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;

double func(){
    string str;
    cin>>str;
    if(str=="+")
        return func() + func();
    if(str=="-")
        return func() - func();
    if(str=="*")
        return func() * func();
    if(str=="/")
        return func() / func();
    return stod(str);
}

int main()
{
    printf("%0.6f\n",func());
    return 0;
}