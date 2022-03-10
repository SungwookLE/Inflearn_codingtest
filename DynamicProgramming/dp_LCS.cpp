#include <iostream>
#include <vector>
#include <string>

using namespace std;
// find Longest Common Sequence between 'A' string and 'B' string
int main(){
    string A, B;
    cin >> A >> B;

    vector<vector<int>> DP(A.length()+1, vector<int>(B.length()+1,0));
    string A_token;
    for(int i = 1 ; i <= A.length(); ++i){
        A_token += A[i-1];
        string B_token;
        for(int j = 1 ; j <= B.length(); ++j){
            B_token += B[j-1];

            if (A_token.back() == B_token.back()){
                DP[i][j] = DP[i-1][j-1]+1;
            }
            else
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
        }
    }


    for(auto elements : DP){
        for(auto element : elements)
            cout << element << " ";
        cout << endl;
    }

    return 0;
}