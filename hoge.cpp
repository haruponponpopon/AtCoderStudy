#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long long N;
    cin >> N;
    int count = 0;
    for (int i=2; i<=sqrt(N); i++){
        while (N%i==0){
            count++;
            N /= i;
        }
    }
    if (N!=1) count++;
    int ans = 0;
    int two = 1;
    while (two<count){
        two *= 2;
        ans++;
    }
    cout << ans << endl;
}