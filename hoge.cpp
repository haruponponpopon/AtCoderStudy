#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct edge{
    int to,cap,rev;
};

void add_edge(int from, int to, int cap, vector<vector<edge>> &network){
    network[from].push_back({to,cap,(int)network[to].size()}); //revは対になってるのが入るindex
    network[to].push_back({from,0,(int)network[from].size()-1}); //逆向き。順方向に対応。
}

int dfs(int current, int goal, int f, vector<bool>&used, vector<vector<edge>>& network){
    if (current==goal) return f;
    used.at(current) = true;

    for (int i=0; i<(int)network[current].size(); i++){
        edge &e = network.at(current).at(i);
        if (!used.at(e.to) && e.cap>0){
            int d = dfs(e.to,goal,min(f,e.cap), used, network);
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
        vector<bool>used(goal+2, false);
        int f = dfs(start,goal,INT_MAX, used, network);
        if (f==0)return flow;
        flow+= f;
    }
}

int main(){
    int N,G,E;
    cin>>N>>G>>E;

    vector<int> p(G);
    for (int i=0; i<G; i++) cin>>p.at(i);

    //グラフを作る。まずはデータの通りに
    vector<vector<edge>> network(N+2);
    for (int i=0; i<E; i++){
        int a,b;
        cin>>a>>b;

        add_edge(a,b,1,network);
        add_edge(b,a,1,network);
    }
    // for (int i=0; i<N+2; i++){
    //     if (network[i].size())cout << "i=" << i << endl;
    //     for (int j=0; j<(int)network[i].size(); j++){
    //         cout << network[i][j].to << " " << network[i][j].cap << " " << network[i][j].rev << endl;
    //     }
    // }

    //女の子がメッセージを閲覧するノード(番号N)を加える。
    for (int i=0; i<G; i++) add_edge(p[i], N, 1, network);

    //bfsで何通りの経路があるかを調べる
    cout << max_flow(0, N, network) << endl;
}