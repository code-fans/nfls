#include <iostream>
using namespace std;

int main(){
    int year, month, day;
    cin >> year >> month >> day;
    int nthDay = day;
    switch(month){
        case 12 :
            nthDay += 30;
        case 11 :
            nthDay += 31;
        case 10 :
            nthDay += 30;
        case 9 :
            nthDay += 31;
        case 8 :
            nthDay += 31;
        case 7 :
            nthDay += 30;
        case 6 :
            nthDay += 31;
        case 5 :
            nthDay += 30;
        case 4 :
            nthDay += 31;
        case 3 :
            nthDay += 28;
            if(year % 400 == 0 || (year % 4 == 0 && year%100 !=0))
                nthDay ++;
        case 2 :
            nthDay += 31;
        case 1:
        default:
            break;
    }
    cout << nthDay << endl;
    return 0;
}