#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main(){
  int N;
  string S,a,b;
  cin >> N;
  map<string,int> dict;
  vector<string> cha;
  for (int i=0; i<N; i++){
    cin >> S;
    dict[S] = 1;
    cha.push_back(S);
  }
  for (int i=0; i<N; i++){
    if (dict.find('!'+cha.at(i))!=dict.end()){
      cout << cha.at(i) << endl;
      return 0;
    }
    if (i==N-1) cout << "satisfiable" << endl;
  } 
}