#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Point{
    int city1;
    int city2;
    int dis;
};

class UnionFind {
public:
	vector<int> par;

	void init(int sz) {
		par.resize(sz, -1);
	}
	int root(int pos) {
		if (par[pos] == -1) return pos;
		par[pos] = root(par[pos]);
		return par[pos];
	}
	void unite(int u, int v) {
		u = root(u); v = root(v);
		if (u == v) return;
		par[u] = v;
	}
	bool same(int u, int v) {
		if (root(u) == root(v)) return true;
		return false;
	}
};

int main(){
    int N,M,c,a,b,r;
    cin >> N >> M;
    vector<Point> distance;
    for (int i=1;i<=N; i++){
        cin >> c;
        distance.push_back({0,i,c});
    }
    for (int i=0; i<M; i++){
        cin>>a>>b>>r;
        distance.push_back({a,b,r});
    }
    sort(distance.begin(), distance.end(), [](const Point &x, const Point &y){return x.dis < y.dis;});

    UnionFind UF;
    UF.init(N+1);
    long long ans = 0;
    for (int i=0; i<(int)distance.size(); i++){
        if (!UF.same(distance.at(i).city1, distance.at(i).city2)){
            UF.unite(distance.at(i).city1, distance.at(i).city2);
            ans += distance.at(i).dis;
        }
    }
    cout << ans << endl;
}