#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct edge{
  int to,cap,rev;
};

void add_edge(int from, int to, int cap, vector<vector<edge>> &network){
  network[from].push_back({to,cap,(int)network[to].size()});
  network[to].push_back({from,0,(int)network[from].size()-1});
}

int dfs(int current, int goal, int f, vector<bool>&used, vector<vector<edge>>& network){
  if (current==goal) return f;
  used.at(current) = true;

  for (int i=0; i<(int)network[current].size(); i++){
    edge &e = network.at(current).at(i);
    if (!used.at(e.to) && e.cap>0){
      int d = dfs(e.to, goal, min(f,e.cap), used,network);
      if (d>0){
        e.cap -= d;
        network.at(e.to).at(e.rev).cap += d;
        return d;
      }
    }
  }
  return 0;
}
int max_flow(int start, int goal, vector<vector<edge>>& network){
  int flow = 0; //flowは経路の数
  while (1){
    vector<bool>used(goal+1, false);
    int f = dfs(start,goal,INT_MAX, used,network);
    if (f==0)return flow;
    flow += f;
  }
}

int main(){
  int N;
  cin>>N;
  vector<vector<edge>> network(2*N+2);
  for (int i=1; i<=N; i++){
    add_edge(0,i, 1, network); //startから赤
    add_edge(N+i,2*N+1,1,network);//青からgoal
  }
  vector<vector<int>> red(N, vector<int>(2));
  vector<vector<int>> blue(N, vector<int>(2));
  //座標を読み込んで条件を満たすならグラフに加える
  for (int i=0; i<N; i++){
    int a,b;
    cin>>a>>b;
    red.at(i).at(0) = a;
    red.at(i).at(1) = b;
  }
  for (int i=0; i<N; i++){
    int c,d;
    cin>>c>>d;
    blue.at(i).at(0) = c;
    blue.at(i).at(1) = d;
  }
  for (int i=0; i<N; i++){
    for (int j=0; j<N; j++){
      if (red.at(i).at(0)<blue.at(j).at(0)&&red.at(i).at(1)<blue.at(j).at(1)){
        add_edge(i+1, N+j+1, 1, network);
      }
    }
  }
  // for (int i=0; i<2*N+2; i++){
  //     if (network[i].size())cout << "i=" << i << endl;
  //     for (int j=0; j<(int)network[i].size(); j++){
  //         cout << network[i][j].to << " " << network[i][j].cap << " " << network[i][j].rev << endl;
  //     }
  // }
  cout << max_flow(0,2*N+1,network) << endl;
}