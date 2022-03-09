#include <iostream>
#include <vector>

using namespace std;

int main(){

    int N, K;
    cin >> N >> K;

    vector<vector<int>>DP(N+1, vector<int>(K+1,0));

    for(int i = 1 ; i <= N ; ++i){

        int W, P;
        cin >> W >> P;

        for(int j = 1; j <= K; ++j){
            if ( j >= W )
                DP[i][j] = max(DP[i-1][j] , DP[i-1][j-W] + P);
            else if ( j < W)
                DP[i][j] = DP[i-1][j];
        }
    }

    cout << DP[N][K] << endl;
    return 0;
}