#include <iostream>
#include <fstream>

using namespace std;
int main(int argc, char *argv[]) {
    if(argc < 5){
        return -1;
    }
    ifstream in, out, ans ;
    ofstream  score;
    in.open(argv[1]);
    out.open(argv[2]);
    ans.open(argv[3]);
    score.open(argv[4]);
    string line;

    while(getline(in, line)){
        score << line << endl;
    }

    while(getline(out, line)){
        score << line << endl;
    }

    while(getline(ans, line)){
        score << line << endl;
    }
    
    in.close();
    out.close();
    ans.close();
    score.close();
    return 0;
}