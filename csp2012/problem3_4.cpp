#include <iostream>
#include <string> // getline(cin, string) 函数
#include <unordered_set>
#include <unordered_map>
using namespace std;

int main(){
    freopen("../csp2012/problem3.in", "r", stdin);
    int n;
    cin >> n;
    unordered_set<string> books; //set
    //unordered_map<string, bool> books; //map
    books.reserve(100);
    string opt, bookname;
    // getline(cin, bookname); 这个会获得 换行符
    for(int i=0; i<n; i++){
        cin >> opt;
        getline(cin, bookname); // 这个会获得 add 和 find 后面的 空格
        if(opt == "add"){
            books.insert(bookname); //set
            //books[bookname] = true; //map
        } else {
            cout << (books.count(bookname) >0 ? "yes":"no")<< endl; //set
            //cout << (books[bookname]? "yes":"no")<< endl; //map
        }
    }
    return 0;
}