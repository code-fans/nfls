#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int y[1000], allY = 0;
    for (int i = 0; i < n; i++){
        cin>>y[i];
        allY+=y[i];
    }
    int maxA = 0;
    for (int i = 1; i <= n-1; i++){
        int a=0,b=0,c=0;
        for(int j=0;j<i;j++){
            a+= y[j];
        }
        int maxB = 0, minA = allY;
        for(int j= i+1; j<=n-1 ; j++){
            b=0;
            for(int k=i; k<j; k++){
                b += y[k];
            }
            c = allY - a -b;
            // a , b , c
            int m = min({a,b,c});
            int M = max({a,b,c});
            int mid = allY - m -M;
            if(mid > maxB){
                maxB = mid;
                minA = m;
            } else if(mid == maxB){
                if(m < minA){
                    minA = m;
                }
            }
        }
        a=0;
        for(int j=i;j<n;j++){
            a+= y[j];
        }
        for(int j = 1; j<i ; j++){
            b=0;
            for(int k=0; k<j; k++){
                b += y[k];
            }
            c = allY - a -b;
            // a , b , c
            int m = min({a,b,c});
            int M = max({a,b,c});
            int mid = allY - m -M;
            if(mid > maxB){
                maxB = mid;
                minA = m;
            } else if(mid == maxB){
                if(m < minA){
                    minA = m;
                }
            }
        }

        if(minA > maxA){
            maxA = minA;
        }
        
    }
    cout << maxA << endl;
    return 0;
}