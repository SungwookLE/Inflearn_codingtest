#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//1. 문제의 조건을 입력받는 변수나 배열은 글로벌 변수로 선언해주는 것이 편리하다.
//2. 배열같은 경우, 딱 맞게 사이즈를 선언하는 것 보다는 문제 조건에서 최대 조건을 따져서 크게 잡아주는 것이,
//   유리한데, 문제를 푸는 데 있어서 불필요하게 발생할 수 있는 메모리 에러를 피할 수 있다.

int N, M;
int sx, sy, fx, fy;
vector<vector<int>> grid(110, vector<int>(110,0));
queue<pair<int, int>> q;
vector<pair<int, int>> delta = { {2,1}, {2, -1}, {-2,1}, {-2, -1},
                                 {1,2}, {1, -2}, {-1,2}, {-1, -2} };

int main(){

    cin >> N >> M;
    cin >> sx >> sy;
    cin >> fx >> fy;
    q.push({sx, sy});

    //---------------- |solution| ----------------
    while(q.size() > 0){

        pair<int, int> now = q.front(); // peek
        q.pop();

        cout << "NOW:{" << now.first << "," << now.second 
        << "}, COUNT:" << grid[now.first][now.second] << endl;
        
        if (now.first == fx && now.second == fy){
            cout << "FIND(BFS): " << grid[fx][fy] << endl;
            return 0;
        }

        for (auto d_move : delta){
            pair<int, int> next = {now.first+d_move.first , now.second+d_move.second}; 
            
            if ((next.first >= 1 && next.second >=1) && (next.first <= N && next.second <= M) && // 장기판 안에서만 움직여야 하고
                (grid[next.first][next.second] == 0) ){  // 방문하지 않은 곳만 추가한다.
                    q.push(next);
                    grid[next.first][next.second] = grid[now.first][now.second]+1;
                }
        }
    }    

    cout << "NO PATH" << endl;
    return 0;
}