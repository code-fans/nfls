#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string> oldForm;
    map<string, set<string> > newForm;
    int n;
    string sn;
    cin>> n;
    for(int i=0; i<n; i++){
        cin >> sn;
        oldForm.push_back(sn);
        string name = sn.substr(0, sn.find('-'));
        string place = sn.substr(sn.find('-')+1);
        newForm[name].insert(place);
    }

    for(int i=0; i<n; i++){
        cout << oldForm[i];
        string name = oldForm[i].substr(0, oldForm[i].find('-'));
        string place = oldForm[i].substr(oldForm[i].find('-')+1);
        for(string s: newForm[name]){
            if(s!=place){
                cout <<',' << s;
            }
        }
        cout << endl;
    }

    return 0;
}