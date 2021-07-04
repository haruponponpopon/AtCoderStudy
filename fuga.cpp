#include <iostream>
#include <vector>
using namespace std;

int main(){
    int H,W;
    cin >> H >> W;
    vector<vector<int>> A(H, vector<int>(W));
    vector<vector<int>> B(H, vector<int>(W));
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            cin >> A.at(i).at(j);
        }
    }
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            cin >> B.at(i).at(j);
        }
    }

    vector<vector<int>> gap(H, vector<int>(W));
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            gap.at(i).at(j) = B.at(i).at(j) - A.at(i).at(j);
        }
    }

    vector<vector<int>> opr(H, vector<int>(W));
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            int index = 0;
            if (i>0) index += opr.at(i-1).at(j);
            if (j>0) index += opr.at(i).at(j-1);
            if (i>0&&j>0) index += opr.at(i-1).at(j-1);
            opr.at(i).at(j) = gap.at(i).at(j) - index;
        }
    }
    long long ans = 0;
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            ans += abs(opr.at(i).at(j));
            if ((i==H-1 || j==W-1)&&opr.at(i).at(j)){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    cout << ans << endl;
}