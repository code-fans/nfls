#include <iostream>
#include <map>
#include <unordered_set>
using namespace std;

unordered_set<int> hashTable;
int main()
{
    hashTable.reserve(3e6);
    long long A,B,C, a0;
    cin>>A>>B>>C;
    a0 = 1;
    hashTable.insert(a0);
    for (int i = 1; i <= 2e6; i++){
        a0=(A*a0+a0%B)%C;
        if(hashTable.count(a0)){
            cout<<i<<endl;
            return 0;
        } 
        hashTable.insert(a0);
    }
    cout<<"-1"<<endl;
    return  0;
}