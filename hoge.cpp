#include <iostream>
#include <queue>
#include <climits>
using namespace std;
struct node{
	int go;
	int k;
	int time;
};
int main(){
	int N,M,X,Y,A,B,T,K;cin>>N>>M>>X>>Y;
	vector<vector<node>> graph(N+1);
	for (int i=0; i<M; i++){
		cin>>A>>B>>T>>K;
		graph[A].push_back({B,K,T});
		graph[B].push_back({A,K,T});
	}
	priority_queue<pair<long long, int>,vector<pair<long long, int>>,greater<>> que;
	vector<bool>used(N+1, false);
	vector<long long>time(N+1,LLONG_MAX);
	que.push({0,X});
	time.at(X) = 0;
	while (!que.empty()){
		auto current = que.top();que.pop();
		if (time[current.second]<current.first) continue;
		// cout<<current.second<<endl;
		used[current.second]=true;
		for (auto next: graph[current.second]){
			if (used[next.go])continue;
			long long arrive = current.first;
			if (arrive%next.k!=0)arrive = (arrive/next.k+1)*next.k;
			arrive += next.time;
			// cout<<next.go<<" "<<arrive<<endl;
			if (arrive<time[next.go]){
				time[next.go] = arrive;
				que.push({arrive, next.go});
			}
		}
	}
	if (time[Y]==LLONG_MAX)cout<<-1<<endl;
	else cout<<time[Y]<<endl;
}