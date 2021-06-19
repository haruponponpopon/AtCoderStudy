#include <iostream>
using namespace std;

long long my_pow(long long a, long long b, long long E){
    long long ans = 1;
    while(b){
        if (b%2==1) ans = ans*a%E;
        a = a*a%E;
        b /= 2; 
    }
    return ans;
}
int main(){
    long long N,K;
    cin >> N >> K;
    long long E = 1e9+7;
    if (N==1){
        cout << K << endl;
        return 0;
    }else if (K==1){
        cout << 0 << endl;
        return 0;
    }
    long long ans = K*(K-1)%E;
    cout << ans*my_pow(K-2, N-2, E)%E << endl;
}