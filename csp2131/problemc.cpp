#include <bits/stdc++.h>
using namespace std;
int heap[5100000], N;

void down(int g) {
    int now, son;
    now = g;
    while (now << 1 <= N) {
        son = now << 1;
        if (son<N && heap[son] > heap[son + 1]) {
            son++;
        }
        if (heap[now] <= heap[son])
            return ;
        swap(heap[now], heap[son]);
        now = son;
    }
}
int main()
{
    cin>>N;
    for (int i = 1; i <= N; i++){
        scanf("%d", heap+i);
    }
    for(int i=(N+1)/2;i>=1;i--){
        down(i);
    }
    for (int i = 1; i <= N; i++){
        printf("%d ",heap[i]);
    }
    return 0;
}