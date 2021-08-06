#include <vector>
#include <iostream>
using namespace std;
int main(){
	int N,M,K,U,V;
	long long E = 998244353;
	cin>>N>>M>>K;
	vector<vector<int>> node(N+1);
	for (int i=0; i<M; i++){
		cin>>U>>V;
		node[U].push_back(V);
		node[V].push_back(U);
	}
	vector<vector<long long>> dp(K+1, vector<long long>(N+1));
	dp.at(0).at(1) = 1;
	for (int i=1; i<=K; i++){
		long long total = 0;
		for (int j=1; j<=N; j++) total += dp.at(i-1).at(j);
		for (int j=1; j<=N; j++){
			dp.at(i).at(j) = total - dp.at(i-1).at(j);
			for (auto k: node[j]){
				dp.at(i).at(j) -= dp.at(i-1).at(k);
			}
			dp.at(i).at(j) %= E;
		}
	}
 	cout << dp.at(K).at(1) << endl;
}