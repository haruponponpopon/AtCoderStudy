#include <iostream>
#include <vector>
using namespace std;
void dfs(vector<int> &color, vector<bool> &used, vector<int> &good, vector<vector<int>> &graph, int current, vector<int> &C){
    if (color.at(C.at(current))==0) good.at(current) = true;
    color.at(C.at(current))++;
    used.at(current) = true;
    for (auto next: graph.at(current)){
        if (used.at(next)==false){
            dfs(color, used,good,graph,next,C);
        }
    }
    color.at(C.at(current))--;
}
int main(){
    int N,A,B;cin>>N;
    vector<int>C(N+1);
    for (int i=1; i<=N; i++)cin>>C.at(i);
    vector<vector<int>> graph(N+1);
    for (int i=0; i<N-1; i++){
        cin>>A>>B;
        graph[A].push_back(B);
        graph[B].push_back(A);
    }
    vector<int>color(1e5+1);
    vector<bool>used(N+1, false);
    vector<int>good(N+1, false);
    dfs(color,used,good,graph,1,C);
    for (int i=1; i<=N; i++){
        if (good.at(i))cout<<i<<endl;
    }
}