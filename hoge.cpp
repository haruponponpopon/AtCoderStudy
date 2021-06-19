#include <iostream>
#include <vector>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i=0; i<N; i++) cin >> A.at(i);
    /*bit全探索*/
    int ans = -1;
    for (int i=0; i<(1<<(N-1)); i++){
        int xored = 0;
        int ored = 0;
        for (int j=0; j<N-1; j++){
            ored |= A.at(j);
            if (1&(i>>j)){
                xored ^= ored;
                ored = 0;
            }
        }
        ored |= A.at(N-1);
        xored ^= ored;
        if (ans==-1||xored<ans) ans = xored;
    }
    cout << ans << endl;
}