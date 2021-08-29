#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int N;cin>>N;
	vector<vector<long long>>CX(N, vector<long long>(2));
	for (auto &cx: CX)cin>>cx.at(1)>>cx.at(0);
	sort(CX.begin(),CX.end(),[](const vector<long long> &x,const vector<long long> &y){return x[0] < y[0];});
	long long left = 0;//経路の最小
	long long right = 0;//経路の最小
	int index = 0;
	long long mini_p = 0; //座標の最小
	long long maxi_p = 0;//座標の最大
	while (index<N){
		long long mini = CX.at(index).at(1);
		long long maxi = CX.at(index).at(1);
		while (index+1<N&&CX.at(index).at(0)==CX.at(index+1).at(0)){
			index++;
			mini = min(mini,CX.at(index).at(1));
			maxi = max(maxi,CX.at(index).at(1));
		}
		long long right_p = right;
		long long left_p = left;
		right = min(right_p+abs(maxi_p-mini), left_p+abs(mini_p-mini))+maxi-mini;
		left = min(right_p+abs(maxi_p-maxi), left_p+abs(mini_p-maxi))+maxi-mini;

		mini_p = mini;
		maxi_p = maxi;
		index++;
	}
	long long ans = min(right+abs(maxi_p), left+abs(mini_p));
	cout<<ans<<endl;
}