#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Tree{
    char data;
    Tree* l;
    Tree* r;
};
int findroot(char root,string str1){
    int w = -1;
    for (int i = 0; i < str1.size(); i++){
        if(str1[i]==root){
            w=i;
            break;
        }
    }
    return w;
}
void aaa(Tree* ans){
    if(ans->l!=nullptr)
        aaa(ans->l);
    if(ans->r!=nullptr)
        aaa(ans->r);
    cout<<ans->data;
}
Tree* mt(string str,string str1){
    Tree * t = new Tree();
    char root=str[0];
    t->data = root;
    int w = findroot(root, str1);
    if(w<=0){
        t->l = nullptr;
    }else{
        string left= str.substr(1, w);
        string left2 = str1.substr(0,w);
        t->l =mt(left, left2);
    }
    if(w>=str.size()-1){
        t->r = nullptr;
    }else{
        string right= str.substr(w+1, str.size()-w-1);
        string right1 = str1.substr(w+1,str1.size()-w-1);
        t->r =mt(right, right1);
    }
    return t;
}
int main()
{
    string str,str1;
    cin>>str;
    cin>>str1;
    Tree* ans=mt(str1,str);
    aaa(ans);
    cout<<endl;
    return 0;
}  