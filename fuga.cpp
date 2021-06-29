#include <vector>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int main(){
    int N,M,u,v,c,u1,c1;
    cin>>N>>M;
    vector<vector<pair<int, int>>> city(N);
    for (int i=0; i<M; i++){
        cin>>u>>v>>c;
        city[u].push_back({v,c});
        city[v].push_back({u,c});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> que;
    long long ans = 0;
    vector<int> used(N);

    /*初期設定*/
    que.emplace(0,0);

    while(!que.empty()){
        auto num = que.top(); que.pop();
        tie(c,u) = num;
        if (used.at(u)) continue;
        used.at(u) = 1;
        ans += c;
        for (auto num1: city.at(u)){
            tie(u1,c1) = num1;
            if (!used.at(u1)) que.emplace(c1,u1);
        }
    }
    cout << ans << endl;
}