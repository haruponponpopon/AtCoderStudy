#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    int H,W;
    long long A,C;
    cin>>H>>W>>C;
    vector<vector<long long>> A1(H, vector<long long>(W));
    vector<vector<long long>> A2(H, vector<long long>(W));
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            cin>>A;
            A1.at(i).at(j) = A;
            A2.at(i).at(W-j-1) = A;
        }
    }
    vector<vector<long long>> dp1(H, vector<long long>(W));
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            if (i==0){
                if (j==0) dp1.at(i).at(j) = A1.at(i).at(j);
                else dp1.at(i).at(j) = min(A1.at(i).at(j), dp1.at(i).at(j-1)+C);
            }else if (j==0) dp1.at(i).at(j) = min(A1.at(i).at(j), dp1.at(i-1).at(j)+C);
            else dp1.at(i).at(j) = min(min(A1.at(i).at(j), dp1.at(i-1).at(j)+C), dp1.at(i).at(j-1)+C);
        }
    }
    long long ans = LLONG_MAX;
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            long long cur;
            if (i==0){
                if (j==0)continue;
                else cur = dp1.at(i).at(j-1) + A1.at(i).at(j);
            }else if (j==0)cur = dp1.at(i-1).at(j) + A1.at(i).at(j);
            else cur = min(dp1.at(i-1).at(j), dp1.at(i).at(j-1))+A1.at(i).at(j);
            ans = min(ans, cur+C);
        }
    }
    //第二弾
    vector<vector<long long>> dp2(H, vector<long long>(W));
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            if (i==0){
                if (j==0) dp2.at(i).at(j) = A2.at(i).at(j);
                else dp2.at(i).at(j) = min(A2.at(i).at(j), dp2.at(i).at(j-1)+C);
            }else if (j==0) dp2.at(i).at(j) = min(A2.at(i).at(j), dp2.at(i-1).at(j)+C);
            else dp2.at(i).at(j) = min(min(A2.at(i).at(j), dp2.at(i-1).at(j)+C), dp2.at(i).at(j-1)+C);
        }
    }
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            long long cur;
            if (i==0){
                if (j==0)continue;
                else cur = dp2.at(i).at(j-1) + A2.at(i).at(j);
            }else if (j==0)cur = dp2.at(i-1).at(j) + A2.at(i).at(j);
            else cur = min(dp2.at(i-1).at(j), dp2.at(i).at(j-1))+A2.at(i).at(j);
            ans = min(ans, cur+C);
        }
    }
    cout << ans << endl;
}