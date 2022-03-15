#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<vector<int>> grid(510, vector<int>(510,0));
vector<vector<int>> DP(510, vector<int>(510,0));

vector<pair<int,int>> delta = {{-1,0}, {1,0}, {0,-1}, {0,1}};

// DFS definition
int DFS(int x, int y){
    // memoization
    if (DP[x][y] != 0)
        return DP[x][y];


    for(auto d : delta){
        int nx = x +d.first;
        int ny = y +d.second;

        if (!(0 <= nx && nx < N && 0 <= ny && ny <N))
            continue;
        if (grid[x][y] >= grid[nx][ny])
            continue;

        DP[x][y] = max(DP[x][y], DFS(nx,ny) + 1);
    }

    return DP[x][y];
}

int main(){
    cin >> N;
    for(int i =0 ; i < N ; ++i){
        for(int j =0 ; j < N ; ++j)
            cin >> grid[i][j];
    }


    // ------------------------ DFS calling ------------------------
    for(int i =0 ; i < N ; ++i){
        for(int j =0 ; j < N ; ++j){
            //memoization
            if (DP[i][j] == 0)
                DP[i][j] = DFS(i,j);
        }
    }

    int max = -1;
    for(int i =0 ; i < N ; ++i){
        for(int j =0 ; j < N ; ++j){
            if (DP[i][j] > max)
                max = DP[i][j];
        }
    }
    

    cout << max << endl;
    return 0;
}