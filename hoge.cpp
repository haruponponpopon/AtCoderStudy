#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class UnionFind {
public:
	vector<int> par;
	vector<int> group;

	void init(int sz) {
		par.resize(sz, -1);
		group.resize(sz, 1);
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
		group[v] = group[u]+group[v];
		// cout<<"group " << v << " "<< group[v]<<endl;
	}
	bool same(int u, int v) {
		if (root(u) == root(v)) return true;
		return false;
	}
	int group_size(int u) {
		// cout << "u " << u  << " " << root(u) << " " << group[root(u)]<< endl;
		return group[root(u)];
	}
};

int main(){
	int N;
	cin>>N;
	vector<vector<int>> node(N-1, vector<int>(3));
	UnionFind UF;
	UF.init(N+1);
	for (auto &n: node) cin>>n.at(0)>>n.at(1)>>n.at(2);
	sort(node.begin(),node.end(),[](const vector<int> &x,const vector<int> &y){return x[2] < y[2];});
	long long ans = 0;
	for (auto &n: node){
		if (UF.same(n.at(0), n.at(1))==false) {
			ans += 1LL*UF.group_size(n.at(0))*UF.group_size(n.at(1))*n.at(2);
			// cout << UF.group_size(n.at(0)) << " " << UF.group_size(n.at(1)) << endl;
			UF.unite(n.at(0),n.at(1));
		}
	}
	cout<<ans<<endl;
}