#include <iostream>
#include <vector>

using namespace std;
int main(){

    // triangle 값 입력받기
    int height;
    cin >> height;
    vector<vector<int>> triangle(height);
    int element;
    for(int i = 1 ; i <= height ; ++i){
        for (int j = 1 ; j <= i ; ++j){
            cin >> element;
            triangle[i-1].push_back(element);
        }
    }

    //solution
    cout << endl;
    cout << "DP array below: "<< endl;
    vector<vector<int>> DP(height+1, vector<int>(height+2,0));
    for(int i = 1; i <= height; ++i){
        for(int j = 1; j <= height - (i-1); ++j){

            DP[i][j] = max( DP[i-1][j] + triangle[height-i][j-1],
                            DP[i-1][j+1] + triangle[height-i][j-1]);

            cout << DP[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "ANSWER: " << DP[height][1] << endl;
    return 0;    
}