#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>>DP(101, vector<int>(101, 0));


int main(){

    int m=4, n=3;
    vector<vector<int>> puddles = {{2,2}};

    for(auto p : puddles)
        DP[p[1]][p[0]] = -1;

    DP[1][1] = 1;

    for(int i = 1; i <= n ; ++i){
        for(int j = 1 ; j <=m ; ++j){

            if (i ==1 && j==1)
                continue;

            if (DP[i][j] != -1){
                if (DP[i-1][j] == -1 || DP[i][j-1] ==-1){
                    if (DP[i-1][j] == -1 && DP[i][j-1] ==-1)
                        DP[i][j] = 0;   
                    else{
                        if (DP[i-1][j] == -1)
                            DP[i][j] = DP[i][j-1];
                        else
                            DP[i][j] = DP[i-1][j];
                    }

                }
                else
                    DP[i][j] = (DP[i-1][j] + DP[i][j-1])%1000000007;
            }
        }
    }

    

    for(int i = 1; i <= n ; ++i){
        for(int j = 1 ; j <=m ; ++j){
            cout << DP[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}