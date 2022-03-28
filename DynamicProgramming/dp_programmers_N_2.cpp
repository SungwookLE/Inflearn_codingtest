// ***._2 is second try of same problem

#include <iostream>
#include <vector>
#include <unordered_set>



using namespace std;


int makenum(int number, int idx){
    int N = number;
    for(int i = 0 ; i < idx ; ++i){
        number = number*10 + N;
    }
    return number;
}

vector<unordered_set<int>> DP(9);


int main(){
    int answer=-1;
    int N, number;
    cin >> N >> number;

    for(int i = 1; i <= 8 ; ++i)
        DP[i].insert(makenum(N,i-1));

    int idx = 1;
    while(idx <= 8){
        for(int i = 1; i <= 8; ++i){
            for(int j = 1; j <= 8; ++j){
                if(i+j == idx){
                    for(auto it1 =DP[i].begin(); it1!=DP[i].end(); it1++){
                        for(auto it2 =DP[j].begin(); it2!=DP[j].end(); it2++){
                            DP[idx].insert(*it1+*it2);
                            DP[idx].insert(*it1**it2);
                            if (*it1 > *it2)
                                DP[idx].insert(*it1-*it2);
                            if (*it1 / *it2 != 0)
                                DP[idx].insert(*it1 / *it2);
                        }
                    }
                }
            }
        }

        if (DP[idx].find(number) != DP[idx].end()){
                answer = idx;
                cout << "Found: " << answer << endl;
                return 0;
            }
        idx++;
    }

    cout << "No Found: " << -1 << endl;

    for(int i = 1; i <= 8 ; ++i){
        for(auto k : DP[i])
            cout << k << " ";
        cout << endl;
    }

    return 0;
}