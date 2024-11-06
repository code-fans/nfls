#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

int pn[10000000];
bool isPrime[10000000];

void simpleFilter(int maxN, bool isPrint){
    memset(isPrime,1,sizeof(isPrime));
    for(int i=2; i*i<=maxN; i++){
        if(isPrime[i]){
            for(int j=i+i; j<=maxN; j+=i){
                isPrime[j] = 0;
            }
        }
    }
    int pSum = 0;
    for(int i=2; i<=maxN; i++){
        if(isPrime[i]){
            if(isPrint){
                if(pSum%10==0)
                    cout<< endl;
                cout << i << ' ';
            }
            pSum ++;  
        }
    }
    cout << endl << "sum = " << pSum << endl;
}

void eratosthenes(int maxN, bool isPrint){
    memset(isPrime,1,sizeof(isPrime));
    for(int i=2; i*i<=maxN; i++){
        if(isPrime[i]){
            for(int j=i*i; j<=maxN; j+=i){
                isPrime[j] = 0;
            }
        }
    }

    int pSum = 0;
    for(int i=2; i<=maxN; i++){
        if(isPrime[i]){
            if(isPrint){
                if(pSum%10==0)
                    cout<< endl;
                cout << i << ' ';
            }
            pSum ++;
            
        }
    }
    cout << endl << "sum = " << pSum << endl;
}

void euler(int maxN, bool isPrint){
    memset(isPrime, 0, sizeof(isPrime));
    int pSum = 0;
    for(int i=2;i<=maxN;i++){
		if(!isPrime[i]) pn[pSum++]=i;
		for(int j=0; j<pSum && i * pn[j]<=maxN; j++){
			isPrime[i*pn[j]]=1;
			if(i%pn[j]==0)break;
		}
	}
    if(isPrint){
        for(int i=0; i<pSum; i++){
            if(i%10==0)
                cout<< endl;
            cout << pn[i] << ' ';
        }
    }
    cout << endl << "sum = " << pSum << endl;
}

void simple(int maxN, bool isPrint){
    pn[0] = 2;
    int pSum = 1;
    for(int i=3; i<=maxN; i++){
        bool isP = true;
        for(int j=0; pn[j]<=sqrt(i+1); j++){
            if(i % pn[j]==0){
                isP = false;
                break;
            }
        }
        if(isP){
            pn[pSum++]=i;
        }
    }

    if(isPrint){
        for(int i=0; i<pSum; i++){
            if(i%10==0)
                cout<< endl;
            cout << pn[i] << ' ';
        }
    }
    cout << endl << "sum = " << pSum << endl;
}

int main(){
    int n = 5000000;

    auto start = std::chrono::high_resolution_clock::now();
    simpleFilter(n, false);
    auto finish = std::chrono::high_resolution_clock::now();
     // 计算持续时间
    std::chrono::duration<double> elapsed = finish - start;
     // 输出运行时间
    std::cout << "simple filter time: " << elapsed.count() << "s\n";

    start = std::chrono::high_resolution_clock::now();
    eratosthenes(n, false);
    finish = std::chrono::high_resolution_clock::now();
    elapsed = finish - start;
    std::cout << "eratosthenes filter time: " << elapsed.count() << "s\n";

    start = std::chrono::high_resolution_clock::now();
    euler(n, false);
    finish = std::chrono::high_resolution_clock::now();
    elapsed = finish - start;
    std::cout << "euler filter time: " << elapsed.count() << "s\n";

    start = std::chrono::high_resolution_clock::now();
    simple(n, false);
    finish = std::chrono::high_resolution_clock::now();
    elapsed = finish - start;
    std::cout << "simple time: " << elapsed.count() << "s\n";

    return 0;
}
