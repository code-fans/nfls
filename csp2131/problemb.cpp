#include <bits/stdc++.h>
using namespace std;
long long N, heapsize = 0, heap[2000005];
void push(long long x) {
    int son, pa;
    heap[++heapsize] = x;
    son = heapsize;
    while (son > 1) {
        pa = son >> 1;
        if (heap[son] >= heap[pa]) {
            return;
        }
        swap(heap[son], heap[pa]);
        son = pa;
    }
}

long long pop() {
    int now, son;
    long long res = heap[1];
    heap[1] = heap[heapsize--];
    now = 1;
    while (now << 1 <= heapsize) {
        son = now << 1;
        if (heap[son] > heap[son + 1]) {
            son++;
        }
        if (heap[now] <= heap[son])
            return res;
        swap(heap[now], heap[son]);
        now = son;
    }
    return res;
}

int main() {
    cin >> N;
    int st,w;
    long long gia=0;
    for (int i = 0; i < N; i++) {
        cin>>st;
        if(st==1){
            cin>>w;
            push(w-gia);
        }else if(st==2){
            cin>>w;
            gia+=w;
        }else{
            cout<<pop()+gia<<endl;
        }
    }
    return 0;
}