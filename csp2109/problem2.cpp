#include <iostream>
#include <vector>
#include <utility>
#include <map>
#include <set>
#include <string>
using namespace std;
int main(){
    vector<pair<string, string> > oldForm;
    map<string, set<string> > newForm;
    string sn;
    int n;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>sn;
        int s=sn.find('-');
        string name = sn.substr(0,s);
        string place = sn.substr(s+1);
        oldForm.push_back({name,place});
        newForm[name].insert(place);
    }
    
    for (int i = 0; i < n; i++){
        cout<<oldForm[i].first<<'-'<<oldForm[i].second;
        for (string s:  newForm[oldForm[i].first]){
            if(s!= oldForm[i].second)
                cout << ',' << s ;
        }
        cout<<endl;
    }
    
    return 0;
}