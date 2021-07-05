#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    /*初期化*/
    int N,M,A,B,C;
    cin>>N>>M;
    vector<vector<long long>> cost(N+1, vector<long long>(N+1, LLONG_MAX/2));
    for (int i=1; i<=N; i++) cost.at(i).at(i) = 0;
    for (int k=0; k<M; k++){
        cin>>A>>B>>C;
        cost.at(A).at(B) = C;
    }
    /*ワーシャルフロイド*/
    long long ans = 0;
    for (int k=1; k<=N; k++){
        for (int i=1; i<=N; i++){
            for (int j=1; j<=N; j++){
                cost.at(i).at(j) = min(cost.at(i).at(j), cost.at(i).at(k)+cost.at(k).at(j));
                ans += (cost.at(i).at(j)==LLONG_MAX/2)?0:cost.at(i).at(j);
            }
        }
    }
    cout << ans << endl;
}