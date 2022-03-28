// *****_2.cpp: second trying of this problem..
// problem is same as _1.cpp

#include <iostream>
#include <vector>

using namespace std;

vector<int> DP(5001);

int main(){
    int coin;
    cin >> coin;

    DP[0] = 0;
    DP[1] = -1;
    DP[2] = -1;
    DP[3] = 1;
    DP[4] = -1;
    DP[5] = 1;


    for(int i = 6; i <= coin ; ++i){
        
        if (DP[i-3] != -1 && DP[i-5] != -1)
            DP[i] = min(DP[i-3]+1 , DP[i-5]+1);

        else if (DP[i-3] == -1 || DP[i-5] == -1){
            if (DP[i-3] == -1 && DP[i-5] == -1)
                DP[i] = -1;
            else if (DP[i-3] == -1)
                DP[i] = DP[i-5]+1;
            else if (DP[i-5] == -1)
                DP[i] = DP[i-3]+1;
        }
    }

    cout << DP[coin] << endl;



    return 0;
}