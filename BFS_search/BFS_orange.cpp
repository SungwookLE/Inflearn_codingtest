#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> grid_orange_box(1010, vector<int>(1010,0));
vector<pair<int, int>> delta = {{-1,0},{1,0},{0,-1},{0,1}};
queue<pair<int, int>> queue_weird_oranges;

int main(){

    cin >> N >> M;
    for(int i = 1 ; i <= N ; ++i){
        for(int j = 1 ; j <= M ; ++j){
            cin >> grid_orange_box[i][j];

            if (grid_orange_box[i][j] == 1)
                queue_weird_oranges.push({i,j});
        }
    }
    
    // ------ |solution| ------ 
    while(!queue_weird_oranges.empty()){
        pair<int, int> now = queue_weird_oranges.front();
        queue_weird_oranges.pop();

        cout << "NOW:{" << now.first << "," << now.second 
        << "}, COUNT:" << grid_orange_box[now.first][now.second] << endl;

        for(auto d : delta){
            pair<int, int> next = {now.first + d.first , now.second + d.second};
            if (next.first >= 1 && next.second >= 1 && next.first <= N && next.second <= M){
                
                if (grid_orange_box[next.first][next.second] == -1)
                    continue;

                if (grid_orange_box[next.first][next.second] == 0){
                    queue_weird_oranges.push(next);
                    grid_orange_box[next.first][next.second] = grid_orange_box[now.first][now.second]+1;
                }
            }
        }
    }

    int days = -1;
    for (int i = 1; i <= N ; ++i){
        for(int j = 1 ; j <= M ; ++j){
            if (grid_orange_box[i][j] == 0){
                cout << "No answer: -1" << endl;
                return 0;
            }
            if (grid_orange_box[i][j] > days){
                days = grid_orange_box[i][j];
            }
        }
    }

    cout << "Answer: " << (days-1) << endl;
    return 0;
}