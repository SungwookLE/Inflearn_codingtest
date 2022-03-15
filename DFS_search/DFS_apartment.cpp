#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N;
void DFS(int x,int y);
vector<vector<int>> grid(30, vector<int>(30,0));
int cnt = 1; // 단지마다 번호를 세기 위함

vector<int> ap(900,0); // 단지마다 몇개 아파트가 속해 있는지 개수를 세기 위함
vector<pair<int,int>> delta = {{1,0}, {-1,0}, {0,1}, {0,-1}};

int main(){
    // ------|check the result| ------
    cin >> N;
    for(int i =0 ; i < N ; ++i){
        string row ;
        cin >> row;
        for(int j =0 ; j < row.length() ; ++j){
            grid[i][j] = row[j]-'0';
        }
    }
    // ------|solution|------ 
    for(int i = 0 ; i < N ; ++i){
        for(int j = 0 ; j < N ; ++j){
            if (grid[i][j] == 1){
                // cnt가 2부터 시작하는 이유: grid에 '1'이라는 정보가 이미 '아파트가 있음'을 알려주는 정보로 사용되고 있기 때문
                cnt += 1;
                // ------|dfs calling|------
                DFS(i,j); 
            }
        }
    }
    // ------|check the result|------
    cout << endl << "APART Complex:" << cnt-1 << endl;
    for(int i = 0 ; i < N ; ++i){
        for(int j =0 ; j < N ; ++j){
            cout << grid[i][j];
        }
        cout << endl;
    }
    // ------|답 출력을 위한 구문|------
    sort(ap.begin()+2, ap.begin()+cnt+1); // 오름차순 정렬
    cout << cnt-1 << " ";
    for(int i =2 ; i <= cnt ; ++i){
        cout << ap[i] << " ";
    }
    return 0;
}

void DFS(int x,int y){
    grid[x][y] = cnt;
    ap[cnt] +=1;
    for(auto d : delta){
        int nx = x + d.first;
        int ny = y + d.second;
        if (!(nx >= 0 && nx < N && ny>=0 && ny <N))
            continue;
        if (!(grid[nx][ny]==1))
            continue;
        DFS(nx, ny);
    }
    return;
}