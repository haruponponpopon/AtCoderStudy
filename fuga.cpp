#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<long long> &x_arr, long long n, long long m){ //xのn進法はmより大きいか
	vector<long long> m_arr;
	while (m){
		m_arr.push_back(m%n);
		m/=n;
	}
	reverse(m_arr.begin(), m_arr.end());
	if (m_arr.size()<x_arr.size())return true;
	else if (m_arr.size()>x_arr.size()) return false;
	for (size_t i=0; i<m_arr.size(); i++){
		if (m_arr[i]<x_arr[i])return true;
		else if (m_arr[i]>x_arr[i])return false;
	}
	return false;
}

int main(){
	string x; long long m; cin>>x>>m;
	long long d = 0;
	vector<long long> arr;
	for (char X: x){
		d = max(d, 1LL*(X - '0'));
		arr.push_back(1LL*(X - '0'));
	}
	if (x.size()==1){
		if (x[0]-'0'>m)cout<<0<<endl;
		else cout<<1<<endl;
		return 0;
	}
	long long ok = d+1;
	long long ng = (long long) 1e18+1;
	// cout<<ng<<endl;
	if (check(arr,ok,m)){
		cout<<0<<endl;
		return 0;
	}
	while (ng-ok>1){
		long long mid = (ok+ng)/2;
		// cout<<ok<<" "<<ng<<" "<<mid<<endl;
		if (check(arr,mid,m)){
			ng = mid;
		}else{
			ok = mid;
		}
	}
	// cout<<ng<<" "<<d+1<<endl;
	cout<<ng-(d+1)<<endl;
}