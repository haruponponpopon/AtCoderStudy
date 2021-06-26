#include <iostream>
#include <string>
#include <vector>
using namespace std;

void search(int current_i, int current_j, vector<string>& c, vector<vector<int>>& used, int depth, int& max_depth, int H, int W, int start_i, int start_j){
    //go down
    if (current_i+1<H && c[current_i+1][current_j]=='.' && !used.at(current_i+1).at(current_j)){
        // cout << 1 << " " << depth << " " << current_i << " " << current_j << endl;
        if (start_i==current_i+1&&start_j==current_j){  //back to start
            if (depth>max_depth) max_depth = depth;
        }else{
            used.at(current_i+1).at(current_j) = 1;
            search(current_i+1, current_j, c, used, depth+1, max_depth, H,W,start_i, start_j);
            used.at(current_i+1).at(current_j) = 0;
        }
    }
    //go up
    if (current_i-1>=0 && c[current_i-1][current_j]=='.' && !used.at(current_i-1).at(current_j)){
        // cout << 2 << " " << depth << endl;
        if (start_i==current_i-1&&start_j==current_j){ //back to start
            if (depth>max_depth) max_depth = depth;
        }else{
            used.at(current_i-1).at(current_j) = 1;
            search(current_i-1, current_j, c, used, depth+1, max_depth, H, W, start_i, start_j);
            used.at(current_i-1).at(current_j) = 0;
        }
    }
    //go left
    if (current_j-1>=0 && c[current_i][current_j-1]=='.' && !used.at(current_i).at(current_j-1)){
        // cout << 3 << " " << depth << " " << current_i << " " << current_j << endl;
        if (start_i==current_i && start_j==current_j-1){ //back to start
            if (depth>max_depth) max_depth = depth;
            // cout << "back to start" << endl;
        }else{
            used.at(current_i).at(current_j-1) = 1;
            // cout << "in 3 :" << current_i << " " << current_j-1 << endl;
            search(current_i, current_j-1, c, used, depth+1, max_depth, H, W, start_i, start_j);
            used.at(current_i).at(current_j-1) = 0;
        }
    }
    //go right
    if (current_j+1<W && c[current_i][current_j+1]=='.' && !used.at(current_i).at(current_j+1)){
        // cout << 4 << " " << depth << " " << current_i << " " << current_j << endl;
        if (start_i==current_i && start_j==current_j+1){
            if (depth>max_depth) max_depth = depth;
        }else{
            used.at(current_i).at(current_j+1) = 1;
            search(current_i, current_j+1, c, used, depth+1, max_depth, H, W, start_i, start_j);
            used.at(current_i).at(current_j+1) = 0;
        }
    }
}

int main(){
    int H,W;
    cin>>H>>W;
    vector<string> c(H);
    for (int i=0; i<H; i++) cin>>c.at(i);
    vector<vector<int>> used(H, vector<int>(W));
    int max_depth = 0;
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            if (c.at(i).at(j)=='.') search(i, j, c, used, 1, max_depth, H, W, i, j);
        }
    }
    if (max_depth<3) cout << -1 << endl;
    else cout << max_depth << endl;
}