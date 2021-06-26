#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <numeric>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<vector<int>> ability(N, vector<int>(5));
    vector<int> max_ability(5);
    for (int i=0; i<N; i++){
        for (int j=0; j<5; j++){
            cin >> ability.at(i).at(j);
            max_ability.at(j) = max(ability.at(i).at(j), max_ability.at(j));
        }
    }
    int ans = 0;
    for (int i=0; i<N-1; i++){
        for (int j=i+1; j<N; j++){ //候補者i,j
            vector<int> candidate(5);
            for (int k=0; k<5; k++) candidate.at(k) = max(ability.at(i).at(k), ability.at(j).at(k));
            vector<int> order(5);
            iota(order.begin(), order.end(),0); 
            sort(order.begin(), order.end(),[&](int x,int y) {
                return candidate[x] > candidate[y];
            });
            ans = max(ans, min(candidate.at(order.at(3)), max_ability.at(order.at(4))));
        }
    }
    cout << ans << endl;
}