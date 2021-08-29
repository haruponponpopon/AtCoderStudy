#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main(){
	int N;cin>>N;
	vector<int>A(N);
	for (auto &a: A)cin>>a;
	int bit_m = 1<<(N-1);
	int ans = INT_MAX;
	for (int i=0; i<bit_m; i++){
		int cur = 0;
		int ins = 0;
		for (int j=0; j<N-1; j++){
			ins |= A.at(j);
			if (1&(i>>j)){
				cur ^= ins;
				ins = 0;
			}
		}
		ins |= A.at(N-1);
		cur ^= ins;
		ans = min(ans, cur);
	}
	cout<<ans<<endl;
}