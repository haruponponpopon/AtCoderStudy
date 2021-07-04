#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N,M,a,b;
    cin >> N >> M;
    vector<int> node(N+1);
    for (int i=0; i<M; i++){
        cin >> a >> b;
        node.at(max(a,b))++;
    }
    int ans=0;
    for (int i=1; i<=N; i++){
        if (node.at(i) == 1) ans++;
    }
    cout << ans << endl;
}