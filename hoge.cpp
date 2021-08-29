#include <iostream>
#include <complex>
using namespace std;
int main(){
	int N;
	double x0,y0,xh,yh;cin>>N>>x0>>y0>>xh>>yh;
	complex<double> p0(x0,y0);
	complex<double> ph(xh,yh);
	complex<double> center = (p0+ph)/2.0;
	complex<double> r = p0-center;
	complex<double> rad = polar(1.0, 2*M_PI/N);
	complex<double> ans = center + r*rad;
	cout<<ans.real()<<" "<<ans.imag()<<endl;
}