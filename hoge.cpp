#include <iostream>
#include <vector>
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
    int H,W,Q,q,r,c,ra,ca,rb,cb;
    cin>>H>>W>>Q;
    UF.init(H*W);
    vector<int> x = {0,0,1,-1};
    vector<int> y = {1,-1,0,0};
    vector<vector<int>> color(H, vector<int>(W)); //while is 0
    for (int i=0; i<Q; i++){
        cin >> q;
        if (q==1){ //paint red (r,c)
            cin>>r>>c;r--;c--;
            color.at(r).at(c) = 1;
            for (int j=0; j<4; j++){
                int nr = r+x.at(j);
                int nc = c+y.at(j);
                if (nr<H&&nr>=0&&nc<W&&nc>=0&&color.at(nr).at(nc)){
                    UF.unite(r*W+c, nr*W+nc);
                    // cout << r*W+c << " " << nr*W+nc << endl;
                }
            }
        }else{
            cin>>ra>>ca>>rb>>cb;
            ra--;ca--;rb--;cb--;
            if (color.at(ra).at(ca) && UF.same(ra*W+ca, rb*W+cb)) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
}