#include <iostream>
#include <complex>
using namespace std;
int main(){
    double N,x0,y0,xn2,yn2;
    cin>>N>>x0>>y0>>xn2>>yn2;
    complex<double> a(x0,y0);
    complex<double> b(xn2,yn2);
    complex<double> c = (a+b)/2.0;
    complex<double> ans = c + (a-c)*polar(1.0, M_PI*2/N);
    cout << ans.real() << " " << ans.imag() << endl;
}