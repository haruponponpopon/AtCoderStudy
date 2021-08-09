#include <iostream>
#include <vector>
#include <string>
#include <climits>
#include <tuple>
#include <deque>
using namespace std;
int main(){
	int H,W;
	cin>>H>>W;
	vector<string> S(H);
	for (auto &s: S) cin>>s;
	vector<vector<int>> dist(H, vector<int>(W, INT_MAX));
	deque<pair<int, int>> que;
	vector<pair<int,int>> go = {{-1,0}, {0,-1}, {1,0}, {0, 1}};
	vector<int> punch = {-2, -1, 0, 1, 2};
	que.push_back({0,0});
	dist.at(0).at(0) = 0;
	while (que.size()){
		auto current = que.front();que.pop_front();
		int c_x = current.first;
		int c_y = current.second;
		/*パンチしないで進む*/
		for (int i=0; i<4; i++){ 
			int n_x = c_x+go.at(i).first;
			int n_y = c_y+go.at(i).second;
			if (n_x<0||n_x>=W||n_y<0||n_y>=H) continue; //領域外に出る
			if (S.at(n_y).at(n_x)=='#') continue; //壁
			if (dist.at(n_y).at(n_x)>dist.at(c_y).at(c_x)){ //距離が更新される
				dist.at(n_y).at(n_x) = dist.at(c_y).at(c_x);
				que.push_front({n_x, n_y});
			}
		}
		/*パンチして進む*/
		for (int i=0; i<5; i++){ 
			for (int j=0; j<5; j++){
				if ((i==0&&j==0)||(i==0&&j==4)||(i==4&&j==0)||(i==4&&j==4)) continue; //そもそも進めない
				int n_x = c_x+punch.at(i);
				int n_y = c_y+punch.at(j);
				if (n_x<0||n_x>=W||n_y<0||n_y>=H) continue; //領域外に出る
				if (dist.at(n_y).at(n_x)>dist.at(c_y).at(c_x)+1){ //距離が更新される
					dist.at(n_y).at(n_x) = dist.at(c_y).at(c_x)+1;
					que.push_back({n_x, n_y});
				}
			}
		}
	}
	cout << dist.at(H-1).at(W-1) << endl;
}