#include <iostream>
#include <string>
#include <vector>
using namespace std;
int hashlen=564937;
vector<string> hashTable[564938];
int hashv(string s){
    int ans=0;
    for (int i = 0; i < s.size(); i++){
        ans=(ans*37+s[i])%hashlen;
    }
    return ans;
}
void add(string str){
    int hashu=hashv(str);
    hashTable[hashu].push_back(str);
}
bool canfind(string str){
    int hashu=hashv(str);
    for (int i = 0; i < hashTable[hashu].size(); i++){
        if(str==hashTable[hashu][i]){
            return true;
        }
    }
    return false;
}
int main()
{
    //freopen("../csp2012/input.in", "r", stdin);
    int n;
    cin>>n;
    string str,str1;
//    getline(cin,str1);
    for (int i = 0; i < n; i++){
        cin>>str;
        getline(cin,str1);
        if(str=="add"){
            add(str1);
        } else {
            if(canfind(str1))
                cout<<"yes\n";
            else
                cout<<"no\n";
        }
    }
    
    return 0;
}