#include <bits/stdc++.h>
using namespace std;
int N, heap[990005],ans[990005];
void maketree(int w, int inheapw, int c){
    ans[w]=heap[inheapw];
    if(c==1) return;
    int mid= (c-1) / 2;
    maketree(w*2, inheapw +mid+1, mid);
    maketree(w*2+1,inheapw+1, mid);
}
int main() {
    cin >> N;
    for (int i = 1; i <= N; i++){
        cin>>heap[i];
    }
    sort(heap+1,heap+1+N);
    maketree(1,1,N);
    for (int i = 1; i <= N; i++){
        cout<<ans[i]<<' ';
    }
    return 0;
}