#include <vector>
#include <iostream>
#include <string>
using namespace std;
int main(){
	int N;string S;cin>>N>>S;
	int E = 998244353;
	vector<vector<vector<int>>> dp(N+1, vector<vector<int>>(1024, vector<int>(10))); //i回目, パターン, 前回の参加

	//bitDP
	for (int i=1; i<=N; i++){ //i回目のコンテスト参加時点
		//まず前回のコンテストのコピー
		for (int j=0; j<1024; j++){
			for (int k=0; k<10; k++){
				dp.at(i).at(j).at(k) = dp.at(i-1).at(j).at(k);
				/*前回の参加と今回のコンテストが一致したら2倍する
				B未
				BB 　　みたいに倍になるから*/
				if (k==S[i-1]-'A') {
					dp.at(i).at(j).at(k) += dp.at(i-1).at(j).at(k);
					dp.at(i).at(j).at(k) %= E;
				}
			}
		}
		int c = S[i-1]-'A';
		//今回のコンテストに、今まで参加していなかったら、その分を加算
		for (int j=0; j<1024; j++){
			if ((1&(j>>c))==0){
				for (int k=0; k<10; k++){
					dp.at(i).at(j+(1<<c)).at(c) += dp.at(i).at(j).at(k);
					dp.at(i).at(j+(1<<c)).at(c) %= E;
				}
			}
		}
		//今回初参加
		dp.at(i).at(1<<c).at(c)++;
		dp.at(i).at(1<<c).at(c) %= E;
	}
	int ans = 0;
	for (int i=0; i<1024; i++){
		for (int j=0; j<10; j++){
			ans += dp.at(N).at(i).at(j);
			ans %= E;
		}
	}
	cout<<ans<<endl;
}