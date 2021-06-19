#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string N;
    int K;
    cin >> N >> K;
    for (int i=0; i<K; i++){
        /*十進法に直す*/
        long long t_N=0;
        for (int j=0; j<(int)N.size(); j++){
            t_N = t_N*8+int(N[j]-'0');
        }
        N = "";
        if (t_N==0) {
            cout << 0 << endl;
            return 0;
        }
        /*9進法に直す*/
        while(t_N){
            long long next_digit = t_N%9;
            if (next_digit==8) N+='5';
            else N+=next_digit+'0';
            t_N /= 9;
        }
        reverse(N.begin(), N.end());
    }
    cout << N << endl;
}