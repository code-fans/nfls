#include <bits/stdc++.h>
using namespace std;
char ans[7][7],cinchar[1000][1000];
bool idans(int x1,int x2,int x3,int x4){
    for(int i=x1;i<x3;i++){
        for(int j=x2;j<x4;j++){
            if(cinchar[i][j]!=ans[i-x1][j-x2]){
                return false;
            }
        }
    }
    return true;
}
int main()
{
    int n;
    cin>>n;
    for (int i = 0; i < 4; i++){
        for(int j=0;j<4;j++){
            if(i==0||i==3)
                ans[i][j]='0';
            else if(j==0||j==3){
                ans[i][j]='0';
            }else{
                ans[i][j]='1';
            }
        }
    }
    for(int t=0;t<n;t++){
        int sizex,sizey;
        cin>>sizex>>sizey;
        for(int i=0;i<sizex;i++)
            for (int j = 0; j < sizey; j++)
                cin>>cinchar[i][j];
        bool can=false;
        for(int x=0;x<=sizex-4;x++){
            for(int y=0;y<sizey-4;y++){
                can=idans(x,y,x+4,y+4);
                if(can)
                    break;
            }
            if(can)
                break;
        }
        if(can)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}