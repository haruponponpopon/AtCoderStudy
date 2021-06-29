#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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
    int N,M;
    cin>>N>>M;
    vector<vector<int>> c(M, vector<int>(3));
    for (int i=0; i<M; i++) cin>>c.at(i).at(0)>>c.at(i).at(1)>>c.at(i).at(2);
    sort(c.begin(),c.end(),[](const vector<int> &x,const vector<int> &y){return x[2] < y[2];});
    UnionFind UF;
    UF.init(N);
    long long ans=0;
    for (int i=0; i<M; i++){
        if (!UF.same(c.at(i).at(0), c.at(i).at(1))){
            ans += c.at(i).at(2);
            UF.unite(c.at(i).at(0), c.at(i).at(1));
        }
    }
    cout << ans << endl;
}   