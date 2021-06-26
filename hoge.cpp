#include <iostream>
#include <cmath>
using namespace std;
int main(){
    long long N;
    cin>>N;
    int ans = 1;
    for (long long i=2; i<=sqrt(N); i++){
        int count = 1;
        while (N%i==0){
            count++;
            N /= i;
        }
        if (i!=2) ans *= count;
    }
    if (N!=1) ans *= 2;
    cout << 2*ans << endl;
}