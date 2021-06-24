#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int N,M,Q,L,R;
    cin>>N>>M>>Q;
    vector<vector<int>>bag(N,vector<int>(2));
    vector<int>box(M);
    for (int i=0; i<N; i++) cin>>bag.at(i).at(0)>>bag.at(i).at(1);
    sort(bag.rbegin(),bag.rend(),[](const vector<int> &x,const vector<int> &y){return x[1] < y[1];});
    for (int i=0; i<M; i++) cin>>box.at(i);
    for (int i=0; i<Q; i++){
        cin>>L>>R;
        vector<int>box1;
        for (int j=0; j<L-1; j++) box1.push_back(box.at(j));
        for (int j=R; j<M; j++) box1.push_back(box.at(j));
        sort(box1.begin(),box1.end());
        int ans = 0;
        vector<int>used((int)box1.size());
        for (int j=0; j<N; j++){ //jは荷物
            for (int k=0; k<(int)box1.size(); k++){ //kは箱
                if (!used.at(k)&&box1.at(k)>=bag.at(j).at(0)){
                    used.at(k) = 1;
                    ans += bag.at(j).at(1);
                    break;
                }
            }
        }
        cout << ans << endl;
    }
}