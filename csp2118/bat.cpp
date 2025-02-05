#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int PN[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
int pn[25] , pns=0;
long long N,K;
vector<long long> dfs1(int b, int e){
	vector<long long> ans;
	if(b==e) return ans;
	if(b == e-1){
		long long v =1,  k = pn[b];
		while(v<=N){
			ans.push_back(v);
			v *= k;
		}
		return ans;
	}
	int mid = (b+e)/2;
	vector<long long> v1 = dfs1(b, mid);
	vector<long long> v2 = dfs1(mid, e);
	if(v1.empty()) return v2;
	if(v2.empty()) return v1;
	sort(v2.begin(), v2.end());
	for(long long i : v1){
		for(long long j : v2){
			if( i*j<=N){
				ans.push_back(i*j);
			}else{
				break;
			}
		}
	}
	// sort(ans.begin(), ans.end());
	return ans;
}

int main()
{
	cin >> N >> K;
	for(int i=0;i<25; i++){
		if(PN[i]<=K){
			pn[pns++] = PN[i];
		}else{
			break;
		}
	}
	//洗牌
	for(int i=0; i<pns/2; i+=2){
		swap(pn[i], pn[pns-1-i]);
	}
	int mid = pns/2;
	vector<long long> a = dfs1(0, mid);
	vector<long long> b = dfs1(mid, pns);
	if(a.empty() || b.empty()){
		cout << a.size() + b.size() << endl;
		return 0;
	}
	sort(b.begin(), b.end());
	long long ans=0;
	for(long long i : a){
		long long k = N/i;
		ans += upper_bound(b.begin(), b.end(), k) - b.begin();
	}
	cout << ans << endl;
	return 0;
}