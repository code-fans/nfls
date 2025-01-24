#include <bits/stdc++.h>
using namespace std;
int hang[9][9],lei[9][9],gong[9][9],cinnum[9][9];
int main()
{
    char in;
    for(int i=0;i<9;i++)
        for(int j=0;j<9;j++){
            cin>>in;
            cinnum[i][j]=in-'0';
            hang[j][cinnum[i][j]]=1;
            lei[i][cinnum[i][j]]=1;
            gong
        }
    return 0;
}