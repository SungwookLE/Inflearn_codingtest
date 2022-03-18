#include <iostream>
#include <vector>
#include <algorithm>

// DFS로 각 노드들의 최대 깊이를 구한다.
// DFS가 반복된 계산을 하는 비효율을 줄이기 위해 Dynamic Programming을 설계해준다. (Memoization)


using namespace std;
int n;
vector<vector<int>> strawbery(510, vector<int>(510,0));
vector<vector<int>> DP(510, vector<int>(510,0));

vector<pair<int, int>> delta = {{-1,0},{1,0},{0,-1},{0,1}};
int DFS(int x, int y);

int main(){
    cin >> n;
    for(int i = 0 ; i < n ; ++i){
        for(int j =0 ; j < n ; ++j){
            cin >> strawbery[i][j];
        }
    }

    // --------------- |DFS calling| ----------------------
    for(int i=0 ; i<n ; ++i){
        for(int j=0 ; j<n ; ++j){
            //memoization 계속해서 불필요한 DFS 함수 호출이 되지 않게끔
            if (DP[i][j] == 0)
                DP[i][j] = DFS(i,j);
        }
    }

    int answer = -1;
    cout << endl <<"DP 배열:\n";
    for(int i = 0 ; i < n ; ++i){
        for(int j =0 ; j < n ; ++j){
            cout << DP[i][j] << " ";
            if (answer < DP[i][j])
                answer = DP[i][j];
        }
        cout << endl;
    }

    cout << endl << "ANSWER: " << answer << endl;
    return 0;
}

int DFS(int x, int y){
    //memoization 계속해서 불필요한 DFS 함수 호출이 되지 않게끔
    if (DP[x][y] != 0)
        return DP[x][y];
    
    for(auto d : delta){
        int nx = x + d.first;
        int ny = y + d.second;

        if (!(nx>=0 && nx < n && ny>=0 && ny < n))
            continue;
        
        if (strawbery[x][y] < strawbery[nx][ny])
            DP[x][y] = max(DP[x][y], DFS(nx,ny)+1);
    }
    return DP[x][y];
}
