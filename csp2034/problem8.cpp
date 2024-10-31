#include <iostream>
#include <string> // getline(cin, string) 函数
using namespace std;

const long long modNum = 1e9+7;
long long ans[2][15]={0};

int main(){
    string str;
    cin >> str;
    int ls = str.size();
    ans[0][0] = 1;
    for(int i=0; i<ls; i++){
        int c = (i+1)%2;
        int p = i%2;

        for(int j =0; j<13; j++){
            ans[c][j] = 0;
        }

        if(str[i]=='?'){
            for(int j=0; j<10; j++){
                for(int k=0; k<13; k++){
                    int t = (k*10+j) % 13;
                    ans[c][t] = (ans[c][t] + ans[p][k]) % modNum;
                }
            }
        } else {
            int j = str[i] - '0';
            for(int k=0; k<13; k++){
                int t = (k*10+j) % 13;
                ans[c][t] = (ans[c][t] + ans[p][k]) % modNum;
            }
        }
    }
    
    cout << ans[ls%2][5] << endl; 
    return 0;
}