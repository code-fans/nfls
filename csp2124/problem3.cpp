#include <iostream>
using namespace std;
char str[25];
int n;
void dfs(int c,int len){
    if(c==n){
        if(len==0){
            str[n]='\0';
            cout<<str<<endl;
        }
        return ;
    }else{
        str[c]='(';
        dfs(c+1,len+1);
        if(len>0){
            str[c]=')';
            dfs(c+1,len-1);
        }
    }
}

int main()
{
    cin>>n;
    if(n%2)
        return 0;
    str[n] = '\0';
    dfs(0,0);
    return 0;
}