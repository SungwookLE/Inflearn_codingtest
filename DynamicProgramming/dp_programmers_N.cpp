#include <iostream>
#include <vector>
#include <unordered_set>
//N 으로 표현: 프로그래머스 Lv3
/*
아래와 같이 5와 사칙연산만으로 12를 표현할 수 있습니다.

12 = 5 + 5 + (5 / 5) + (5 / 5)
12 = 55 / 5 + 5 / 5
12 = (55 + 5) / 5

5를 사용한 횟수는 각각 6,5,4 입니다. 그리고 이중 가장 작은 경우는 4입니다.
이처럼 숫자 N과 number가 주어질 때, N과 사칙연산만 사용해서 표현 할 수 있는 방법 중 N 사용횟수의 최솟값을 return 하도록 solution 함수를 작성하세요.

** 제한사항
- N은 1 이상 9 이하입니다.
- number는 1 이상 32,000 이하입니다.
- 수식에는 괄호와 사칙연산만 가능하며 나누기 연산에서 나머지는 무시합니다.
- 최솟값이 8보다 크면 -1을 return 합니다.
*/

#define max_K 8
using namespace std;

int get_Ns(int N, int idx){
    int Ns=N;
    for(int i = 1 ; i < idx ; ++i){
        Ns = Ns*10 + Ns;
    }
    return Ns;
}

int main(){
    int N, number;
    cin >> N >> number;
    vector<unordered_set<int>> DP(max_K+1);
    DP[0].insert(0); //trivial case
    for(int k = 1; k <= max_K; ++k){
        DP[k].insert(get_Ns(N, k));
    
        for(int i = 1 ; i <= k; ++i){
            for(int j = 1;  j<= k ; ++j){
                if ((i+j) != k)
                    continue;

                for(int p : DP[i]){
                    for(int q: DP[j]){
                        DP[k].insert(p+q);
                        DP[k].insert(p*q);

                        if ( p - q > 0)
                            DP[k].insert(p-q);
                        if ( p / q > 0 )
                            DP[k].insert(p/q);
                    }
                }
            }
        }

        if( DP[k].find(number) != DP[k].end()){
            cout << "Find: " << *(DP[k].find(number)) << endl; // 
            cout << "ANSWER: " << k << endl;
            return k;
        }
    }
    cout << "ANSWER: " << -1 << endl;
    return -1;
}

//bottom-up 방식으로 풀었고 고정된 2차원 배열이 아니라, 유동적인 2차원 배열을 사용
//배열의 효율성을 높히기 위해 STL중 unordered_set 을 사용하여 중복되는 숫자는 따로 제거
//나누기 0이 되는 