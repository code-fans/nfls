#include <iostream>
using namespace std;
int lr[9][9], ud[9][9], matrix[9][9];
int heng[9], zhong[9], gong[9];
bool dfs(int x, int y){
    int l=1, r=9;
    if(lr[x][y] == 1){
        l = matrix[x][y-1] + 1;
    } else if(lr[x][y] == 2){
        r = matrix[x][y-1] - 1;
    }
    if(ud[x][y] == 1 && matrix[x-1][y] >= l){
        l = matrix[x-1][y] + 1;
    } else if(ud[x][y] == 2 && matrix[x-1][y] <= r){
        r = matrix[x-1][y] - 1;
    }
    int g = x/3*3 + y/3;
    for(int i = l; i<=r; i++){
        unsigned int bit = 1<<i;
        if(!((heng[x] & bit) || (zhong[y] & bit) || (gong[g] & bit))){
            matrix[x][y] = i;
            heng[x] += bit;
            zhong[y] += bit;
            gong[g] += bit;
            if(x==8 && y==8) return true;
            if(y==8){
                if(dfs(x+1, 0)) return true;
            }else{
                if(dfs(x, y+1)) return true;
            }
            heng[x] -= bit;
            zhong[y] -= bit;
            gong[g] -= bit;
        }
    }
    return false;
}
int main(){
    // freopen("../csp2172/input.txt","r", stdin);
    char c;
    for(int i=0; i<15; i++){
        if(i % 5 % 2){
            int x = i / 5 * 3 + ( i % 5 == 3? 2:1);
            for(int j=0; j<9; j++){
                cin >> c;
                ud[x][j] = c=='v'? 2 : 1; 
            }
        } else {
            int x = i / 5 * 3 + i % 5 / 2;
            for(int j=0; j<9; j++){
                if(j % 3){
                    cin >> c;
                    lr[x][j] = c=='<'? 1 : 2; 
                }
            }
        }
    }
    dfs(0, 0);
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << matrix[i][j] << ' ';
        }
        cout << endl;
    }
    return 0;
}
