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
    int N;
    cin>>N;
    vector<vector<int>> x(N, vector<int>(2));
    vector<vector<int>> y(N, vector<int>(2));

    for (int i=0; i<N; i++){
        cin>>x.at(i).at(0)>>y.at(i).at(0);
        x.at(i).at(1) = i;
        y.at(i).at(1) = i;
    }

    sort(x.begin(),x.end(),[](const vector<int> &x1,const vector<int> &y1){return x1[0] < y1[0];});
    sort(y.begin(),y.end(),[](const vector<int> &x1,const vector<int> &y1){return x1[0] < y1[0];});

    // for (int i=0; i<N; i++) cout << x.at(i).at(0) << " " << x.at(i).at(1) << endl;

    vector<Point> distance;
    for (int i=1; i<N; i++) {
        distance.push_back({x.at(i-1).at(1), x.at(i).at(1), abs(x.at(i-1).at(0)-x.at(i).at(0))});
        distance.push_back({y.at(i-1).at(1), y.at(i).at(1), abs(y.at(i-1).at(0)-y.at(i).at(0))});
    }
    sort(distance.begin(),distance.end(),[](const struct Point &x1,const struct Point &y1){return x1.dis < y1.dis;});

    long long ans = 0;

    UnionFind UF;
    UF.init(N);
    for (int i=0; i<(int)distance.size(); i++){
        if (!UF.same(distance.at(i).city1, distance.at(i).city2)){
            UF.unite(distance.at(i).city1, distance.at(i).city2);
            ans += distance.at(i).dis;
        }
    }
    cout << ans << endl;
}