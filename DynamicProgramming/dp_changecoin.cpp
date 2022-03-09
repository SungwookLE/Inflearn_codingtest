#include <iostream>
#include <vector>
#define X -1 //X표 쳤다는 의미는 낼 수 있는 동전이 없다는 뜻

using namespace std;

int main(){

    int N;
    cin >> N;

    vector<int> DP(N+1, 0);

    //bottom - up
    // 1) 초항
    DP[0] = 0;
    DP[1] = X;
    DP[2] = X;
    DP[3] = 1;
    DP[4] = X;
    DP[5] = 1;

    // 2) 점화식
    // DP[6] = min(DP[6-3]+1 , DP[6-5]+1);
    //        = min(DP[3]+1, DP[1]+1);
    //        = min(DP[3]+1)

    for(int i = 6 ; i <= N ; ++i){

        if (DP[i-3] == X){
            if (DP[i-5] == X)
                DP[i] = X;
            else if (DP[i-5] != X)
                DP[i] = DP[i-5]+1;
        }
        else if (DP[i-3] != X){
            if (DP[i-5] == X)
                DP[i] = DP[i-3]+1;
            else if (DP[i-5] != X)
                DP[i] = min(DP[i-3]+1, DP[i-5]+1);
        }
    }
    cout << DP[N] << endl;

    return 0;
}