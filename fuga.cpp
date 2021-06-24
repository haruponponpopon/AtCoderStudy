#include <iostream>
#include <vector>
#include <deque>
#include <tuple>

using namespace std;

int main(){
    int N,a,b;
    cin >> N;
    vector<pair<int,int>> edge;
    vector<vector<int>> g(N+1);
    edge.push_back({NULL, NULL});
    for (int i=1; i<N; i++){
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
        edge.push_back({a,b});
    }
    vector<int>depth(N+1, -1);
    deque<int> dq;
    vector<bool>used(N+1,false);
    dq.push_back(1);
    depth.at(1) = 0;
    used.at(1) = true;
    while (!dq.empty()){
        int now = dq.front();
        dq.pop_front();
        for (int i: g[now]) {
            if (used.at(i)==false){
                depth.at(i) = depth.at(now)+1;
                used.at(i)=true;
                dq.push_back(i);
            }
        }
    }
    
    vector<long long> S(N+1, 0);
    int Q,t,e;
    long long x;
    cin >> Q;
    for (int i=0; i<Q; i++){
        cin>>t>>e>>x;
        tie(a,b) = edge.at(e);
        if (depth.at(a)>depth.at(b)) {
            swap(a,b);
            t ^= 3;
        }
        if (t==1){
            S.at(1) += x;
            S.at(b) -= x;
        }else{
            S.at(b) += x;
        }
    }

    vector<long long> ans(N+1);
    dq.push_back(1);
    used.at(1) = false;
    ans.at(1) = S.at(1);
    while (!dq.empty()){
        int now = dq.front();
        dq.pop_front();
        for (int i: g[now]) {
            if (used.at(i)==true){
                ans.at(i) = ans.at(now) + S.at(i);
                used.at(i)=false;
                dq.push_back(i);
            }
        }
    }
    for (int i=1; i<=N; i++) cout << ans.at(i) << endl;
}