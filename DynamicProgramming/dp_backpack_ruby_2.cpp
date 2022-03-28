// ***_2.cpp is second try of same problem

#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> DP(10001, vector<int>(1001,0));
vector<pair<int, int>> ruby={{0,0}};

int main(){

    int N , K;
    cin >> N  >> K ;

    for(int i =0 ; i < N ; ++i){
        int w, p;
        cin >> w >> p;
        ruby.push_back({w,p});
    }

    for(int i = 1 ; i <= N; ++i){
        for(int j =1 ; j <= K ; ++j){

            if (ruby[i].first <= j)
                DP[i][j] = max(DP[i-1][j] , DP[i-1][j-ruby[i].first] + ruby[i].second);            
            else
                DP[i][j] = DP[i-1][j];
        }
    }

    for(int i = 1 ; i <= N; ++i){
        for(int j = 1 ; j <= K ; ++j)
            cout << DP[i][j] << " ";
        cout << endl;
    }

    return 0;
}