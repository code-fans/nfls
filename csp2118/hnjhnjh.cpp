#include <bits/stdc++.h>
using namespace std;
long long x[100100],y;
vector <int> arr[100100];
int main()
{
    long long m,n,k;
    cin>>m>>n>>k;
    for (int i = 0; i < n; i++)
        cin>>x[i];
    for (int i = 0; i < n; i++){
        cin>>y;
        arr[x[i]].push_back(y);
    }
    long long all,ans=0,maxshu=0;
    int maxl;
    for (int i = 1; i <= m; i++){
        long long she=0;
        sort(arr[i].begin(),arr[i].end(),greater<int>());
        //vector<int>::iterator
        all=0;
        for(int a : arr[i]){
            she++;
            all += a;
            if(all>=k)
                break;
        }
        if(all<k){
            cout<<-1<<endl;
            return 0;
        }
        if(maxshu<she){
            maxshu=she;
            maxl=arr[i].size();
        }
        ans+=she;
    }
    if(maxshu*2-1>n-maxl)
        cout<<-1<<endl;
    else
        cout<<max(maxshu*2-1,ans)<<endl;
    return 0;
}