#include <bits/stdc++.h>
using namespace std;
int bida(char a){
    if(a=='(')
        return 4;
    if(a=='*'||a=='/')
        return 3;
    if(a=='+'||a=='-')
        return 2;
    return 1;
}
long long jisuan(long long a,long long b,char c){
    if(c=='*')
        return a*b;
    if(c=='/')
        return a/b;
    if(c=='+')
        return a+b;
    if(c=='-')
        return a-b;
}
int main(){
    int a[100000],sizea=0,sizeb=0;
    char b[100000];
    string str;
    cin>>str;
    str.push_back(')');
    //...)
    long long num=0,ismun=0;
    for (int i = 0; i < str.size(); i++){
        if(str[i]>='0'&&str[i]<='9'){
            num=num*10+str[i]-'0';
            ismun=1;
        } else {
            if(ismun){
                a[sizea]=num;
                sizea++;
                ismun=0;
                num=0;
            }
            while (sizeb>=1&&bida(str[i])<=bida(b[sizeb-1])&&b[sizeb-1]!='('){
                a[sizea-2]=jisuan(a[sizea-2],a[sizea-1],b[sizeb-1]);
                sizeb--;
                sizea--;
            }
            //()
            if(sizeb>0&&b[sizeb-1]=='('&&str[i]==')')
                sizeb--;
            else{
                b[sizeb]=str[i];
                sizeb++;
            }
        }
    }
    cout<<a[0]<<endl;
    return 0;
}
