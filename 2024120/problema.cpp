#include <bits/stdc++.h>
using namespace std;
deque<long long> num;
int main()
{
    long long n;
    cin>>n;
    long long lei,shu;
    for (int i = 0; i < n; i++){
        cin>>lei>>shu;
        if(lei==1){
            num.push_front(shu);
        }else if(lei==2){
            num.push_back(shu);
        }else{
            cout<<num[shu-1]<<endl;
        }
    }
    return 0;
}