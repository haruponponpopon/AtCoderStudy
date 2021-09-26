#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
int main(){
	int N,M,A,B,C;cin>>N>>M;
	vector<vector<pair<int, int>>>graph(N+1);
	for (int i=0; i<M; i++){
		cin>>A>>B>>C;
		graph[A].push_back({B,C});//ノード,距離
	}
	for (int start=1; start<=N; start++){
		// cout<<start<<endl;
		priority_queue<pair<int, int>,vector<pair<int, int>>,greater<>> que;//距離、ノード
		que.push({0,start});
		vector<int> min_dis(N+1, INT_MAX);
		int ans = INT_MAX;
		while (!que.empty()){
			auto current = que.top(); que.pop();//距離,ノード
			if (min_dis.at(current.second)<current.first)continue;
			for (auto next: graph[current.second]){//ノード、距離
				if (next.first ==start)ans = min(ans, current.first+next.second);
				else{
					if (min_dis.at(next.first)>current.first+next.second){
						min_dis.at(next.first) = current.first+next.second;
						que.push({current.first+next.second,next.first});
					}
				}
			}
		}
		if (ans==INT_MAX)cout<<-1<<endl;
		else cout<<ans<<endl;
	}
}