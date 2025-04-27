#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <cmath>
using namespace std;
vector<pair<long long, long long> > site;
vector<pair<long long, long long> > van;

bool cmpVan(pair<long long, long long> & a, pair<long long, long long> & b){
    return abs(a.first - a.second) > abs(b.first- b.second);
}
int n,m,x;
int main(){
    int a,b;
    cin >> n >> m >> x;
    for(int i=0; i<n; i++){
        cin >> a >> b;
        site.push_back(make_pair(a,b));
    }
    for(int i=0; i<m; i++){
        cin >> a >> b;
        van.push_back(make_pair(a,b));
    }
    sort(site.begin(), site.end());
    sort(van.begin(), van.end(), cmpVan);
    long long ans = 0;
    for(int i=0; i<van.size(); i++){
        pair<long long, long long> & truck = van[i];
        if(truck.first > truck.second){
            for(int j=0; j<site.size(); j++){
                pair<long long, long long> & v = site[j];
                if(v.second > 0){
                    v.second --;
                    ans += truck.first * v.first * 2 + truck.second * (x-v.first) * 2;
                    break;
                }
            }
        } else {
            for(int j=site.size()-1; j>=0; j--){
                pair<long long, long long> & v = site[j];
                if(v.second > 0){
                    v.second --;
                    ans += truck.first * v.first * 2 + truck.second * (x-v.first) * 2;
                    break;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}