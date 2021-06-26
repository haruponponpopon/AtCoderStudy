#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    long long total = 0;
    cin >> N;
    vector<long long> A(N);
    for (int i=0; i<N; i++){
        cin >> A.at(i);
        total += A.at(i);
    }
    if (total%10){
        cout << "No" << endl;
        return 0;
    }
    long long piece = total/10;

    int index1 = 0;
    int index2 = 0;
    long long cake = A.at(0);
    while (index1<N){
        // cout << index1 << " " << index2 << " " << cake << endl;
        if (cake==piece){
            cout << "Yes" << endl;
            return 0;
        }else if (cake>piece) {
            cake -= A.at(index1);
            if (index1!=index2) index1++;
            else {
                if (index2==N-1) index2 = -1;
                index1++;
                index2++;
                if (index1<N) cake += A.at(index1);
            }
        }else{
            if (index2==N-1) index2 = -1;
            index2++;
            cake += A.at(index2);
        }
    }
    cout << "No" << endl;
}