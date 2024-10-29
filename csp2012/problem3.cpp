#include <iostream>
#include <string> // getline(cin, string) 函数
using namespace std;
#define HASHSIZE 564937
string hashTable[HASHSIZE+1];
int hashValue(string s){
    int value = 0;
    for(int i=0; i<s.size(); i++){
        value = (value * 37 + s[i]) % HASHSIZE;
    }
    return value;
}
void add(string s){
    int pos = hashValue(s);
    for(int i = pos; i<HASHSIZE; i++){
        if(hashTable[i].empty() || hashTable[i] == s){
            hashTable[i] = s;
            return;
        }
    }
    for(int i = 0; i<pos; i++){
        if(hashTable[i].empty() || hashTable[i] == s){
            hashTable[i] = s;
            return;
        }
    }
}
int find(string s){
    int pos = hashValue(s);
    for(int i = pos; i<HASHSIZE; i++){
        if(hashTable[i] == s){
            return i;
        }
        if(hashTable[i].empty()){
            return -1;
        }
    }
    for(int i = 0; i<pos; i++){
        if(hashTable[i]== s){
            return i;
        }
        if(hashTable[i].empty()){
            return -1;
        }
    }
    return -1;
}
int main(){
    freopen("../csp2012/problem3.in", "r", stdin);
    int n;
    cin >> n;
    string opt, bookname;
    for(int i=0; i<n; i++){
        cin >> opt;
        getline(cin, bookname);
        if(opt == "add"){
            add(bookname);
        } else {
            cout << (find(bookname) >=0 ? "yes":"no")<< endl;
        }
    }
    return 0;
}