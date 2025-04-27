#include <bits/stdc++.h>
using namespace std;

long long num[7][7];

pair<long long, long long> calc(const int zm[]){
    long long tmpsum[8][7] = {{0}};
    bool fisrt = true;
    for(int i=0; i<7; i++){
        if(zm[i]==0){
            for(int j=0; j<7; j++)
                tmpsum[i+1][j] = tmpsum[i][j]; 
        }else{
            for(int j=0; j<7; j++){
                if(num[i][j]>0){
                    if(fisrt){
                        int mb = j*zm[i] % 7;
                        tmpsum[i+1][mb] += num[i][j];
                    } else {
                        for(int k=0; k<7; k++){
                            int mb = (k + j*zm[i]) % 7;
                            tmpsum[i+1][mb] += tmpsum[i][k] * num[i][j];
                        }
                    }
                }
            }
            fisrt = false;
        }
    }
    long long sum=0;
    for(int i=0; i<7; i++){
        sum += tmpsum[7][i];
    }
    return {sum, tmpsum[7][0]};
}

int main()
{
    map<char, int> ids;
    ids['B'] = 0;
    ids['E'] = 1;
    ids['S'] = 2;
    ids['I'] = 3;
    ids['G'] = 4;
    ids['O'] = 5;
    ids['M'] = 6;

    int n,v;
    char c;
    cin>>n;
    while(n--){
        cin >> c >> v;
        int i = ids[c];
        int ys = (v+700000)%7;
        num[i][ys] ++;
    }
    // BEESSI // GOES // MOO
    int arr1[] = {1,2,2,1,0,0,0};
    int arr2[] = {0,1,1,0,1,1,0};
    int arr3[] = {0,0,0,0,0,2,1};
    pair<long long, long long> ap = calc(arr1);
    pair<long long, long long> bp = calc(arr2);
    pair<long long, long long> cp = calc(arr3);

    long long ans = ap.second * bp.first * cp.first 
            + ap.first * bp.second * cp.first
            + ap.first * bp.first * cp.second
            - ap.second * bp.second * cp.first
            - ap.first * bp.second * cp.second
            - ap.second * bp.first * cp.second
            + ap.second * bp.second * cp.second;
    cout << ans << endl;
    return 0;
}