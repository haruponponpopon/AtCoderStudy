#include <iostream>
#include <deque>
#include <string>
using namespace std;
int main(){
    string S;
    cin>>S;
    int flag = 0;
    deque<char> q;
    for (int i=0; i<(int)S.size(); i++){
        if (S[i]=='R') flag ^= 1;
        else {
            if (flag){
                if (!q.empty() && S[i]==q.front()) q.pop_front();
                else q.push_front(S[i]);
            }else{
                if (!q.empty() && S[i]==q.back()) q.pop_back();
                else q.push_back(S[i]);
            }
        }
    }
    if (flag) {
        while (!q.empty()){
            cout << q.back();
            q.pop_back();
        }
    }else{
        while(!q.empty()){
            cout << q.front();
            q.pop_front();
        }
    }
}