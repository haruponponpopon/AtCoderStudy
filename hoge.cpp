#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int gcd (int a,int b) {return (a%b ? gcd(b,a%b): b);}

int main(){
	int N,M;
	cin>>N>>M;
	vector<vector<int>> AC(M, vector<int>(2));
	for (int i=0; i<M; i++) cin>>AC.at(i).at(0)>>AC.at(i).at(1);
	sort(AC.begin(),AC.end(),[](const vector<int> &x,const vector<int> &y){return x[1] < y[1];});
	int group = N;
	long long ans = 0;
	for (int i=0; i<M; i++){
		int a = AC.at(i).at(0);//x
		int c = AC.at(i).at(1);//cost
		ans += 1LL*(group-gcd(group, a))*c;
		group = gcd(group, a);
	}
	if (group==1) cout << ans << endl;
	else cout << -1 << endl;
}