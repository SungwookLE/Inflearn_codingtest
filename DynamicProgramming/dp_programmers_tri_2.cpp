// ***_2.cpp is second try of same problem.
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> DP(501, vector<int>(501,0));
vector<vector<int>> tri;

int main(){

    int h;
    cin >> h;

    for(int i = 1 ; i<=h ; ++i){
        vector<int> row(i,0);
        for(int j = 0 ; j < i; ++j){
            cin >> row[j];
        }
        tri.push_back(row);
    }


    DP[0] = tri.back();
    tri.pop_back();

    for(int i = 1 ; i < h ; ++i){
        for(int j = 0 ; j < (h-i) ; ++j)
            DP[i][j] = max(DP[i-1][j], DP[i-1][j+1])+tri.back()[j];
        tri.pop_back();
    }


    // inverse accumulate
    for(int i = 0 ; i < h; ++i){
        for(int j = 0 ; j < (h-i); ++j)
            cout << DP[i][j] << " ";
        cout << endl;
    }

    cout << "ANSWER: " << DP[h-1][0] << endl;

    return 0;
}