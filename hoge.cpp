#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<int> X(N);
    vector<int> Y(N);
    for (int i=0; i<N; i++) cin >> X.at(i) >> Y.at(i);
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    /*発電所の場所*/
    int x = X.at(N/2);
    int y = Y.at(N/2);
    long long ans = 0;
    for (int i=0; i<N; i++){
        ans += abs(X.at(i)-x);
        ans += abs(Y.at(i)-y);
    }
    cout << ans << endl;
}