#include <iostream>
#include <vector>
#include <numeric>
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
    void print(){
        for (int i=0; i<(int)par.size(); i++) cout << par.at(i) << " ";
        cout << endl;
    }
};

int main(){
    UnionFind UF;
    int N;
    cin>>N;
    vector<int> A(N);
    for (int i=0;i<N;i++) cin>>A.at(i);
    UF.init(200001);
    int ans = 0;
    for (int i=0; i<N/2; i++){
        if (A.at(i)==A.at(N-i-1))continue;
        else if (UF.same(A.at(i), A.at(N-i-1))) continue;
        else{
            ans++;
            UF.unite(A.at(i), A.at(N-i-1));
        }
    }
    cout << ans << endl;
}