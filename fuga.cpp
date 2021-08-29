#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
using namespace std;
long long convert_to_num(vector<int>& digit, string& S, vector<int>& abc){
    //一番最初の桁が0だったらエラーの-1を返す。
    if (digit.at(abc.at(S[0]-'a'))==0)return -1;
    long long ans = 0;
    for (auto s: S){
        ans = ans*10 + digit.at(abc.at(s-'a'));
    }
    return ans;
}
int main(){
    vector<string>S(3);
    for (auto &s:S)cin>>s;
    vector<int>abc(26,-1);
    int count = 0;
    for (int i=0; i<3; i++){
        for (auto s: S[i]){
            if (abc.at(s-'a')==-1){
                abc.at(s-'a')=count;
                count++;
            }
        }
    }
    if (count>10){
        cout<<"UNSOLVABLE"<<endl;
        return 0;
    }
    vector<int>digit(10);
    iota(digit.begin(), digit.end(),0);
    do {
        vector<long long> N(3);
        bool flag = true;
        for (int i=0; i<3; i++){
            N.at(i) = convert_to_num(digit,S.at(i),abc);
            if (N.at(i)==-1)flag = false;
        }
        if (N.at(0)+N.at(1)==N.at(2)&&flag){
            for (auto n: N)cout<<n<<endl;
            return 0;
        }
    }while(next_permutation(digit.begin(), digit.end())); //vectorで書くならこう
    cout<<"UNSOLVABLE"<<endl;
}