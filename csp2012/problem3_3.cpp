#include <iostream>
#include <string> // getline(cin, string) 函数
using namespace std;
#define HASHSIZE 564937

int hashTable[HASHSIZE+1];
int books = 0;
string booknames[HASHSIZE];

int hashValue(string s){
    int value = 0;
    for(int i=0; i<s.size(); i++){
        value = (value * 37 + s[i]) % HASHSIZE;
    }
    return value;
}

void add(string s){
    int pos = hashValue(s);
    for(int i = 0; i<HASHSIZE; i++, pos=(pos+1)%HASHSIZE){
        if(hashTable[pos]==0){
            books++;
            booknames[books] = s;
            hashTable[pos] = books;
            return ;
        }
        if(booknames[hashTable[pos]] == s){
            return ;
        }
    }
}

int find(string s){
    int pos = hashValue(s);
    for(int i = pos; i<HASHSIZE; i++, pos=(pos+1)%HASHSIZE){
        if(hashTable[i] == 0){
            return -1;
        }
        if(booknames[hashTable[i]] == s){
            return hashTable[i];
        }
    }
    return -1;
}
int main(){
    freopen("../csp2012/problem3.in", "r", stdin);
    int n, books=1;
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