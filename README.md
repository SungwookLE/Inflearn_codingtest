# CodingTest prepare with `c++`
- INFLEARN LECTURE: IT 기업 취업을 위한: 코딩 테스트 혼자서 정복하기 (26,400원)
- Writer: Sungwook LE
- DATE: '22.3/9~
- LANGUAGE: `C++`
- 목표:
    1. 문제가 요구하는 알고리즘을 파악할 수 있다.
    2. 최소한의 문법으로 최대한 깔끔한 코드를 작성할 수 있다. 
    3. 공통적으로 출제되는 문제의 **템플릿**을 작성/이해하고 이를 통해 문제를 풀자.

## 1. 동적프로그래밍
- Dynamic Programming = **분할정복 프로그래밍**
- 분할정복 풀이: `Bottom-up` 방식으로 점화식(`recurrence relation`)을 유도하여 풀자
    - 문제를 직접 풀려고 `if`문을 생각하게 되면, 여러 예외조건에 막혀 문제를 풀 수 없게된다는 것을 명심
    - 분할정복 문제는 배열을 이용해서 풀게되는데, 이 때!, `0` 번째 케이스에 대한 값을 0과 같은 default 값을 넣어줌으로써 `trivial case` 에 대한 값을 명시적으로 배열을 채워서 풀자.
  
### 1-1. 분할정복 풀이를 위한 점화식
1. 수열의 n번째 값 $a_n$을 구하기 위해 따라야 하는 규칙
2. $a_n$을 구하기 위해서는, $a_1$부터 순서대로 계산해야 함

### 1-2. 점화식은 Bottom-Up으로 풀자 
- 점화식이 아래와 같을 때, $a_5$를 구하여라.
    - $a_1 = 3$ 
    - $a_n = 2a_{n-1}-4$

- Solution: Bottom-up 접근
    - Note: Top-down 방식으로 풀어야하는 문제도 있으나, 대부분 Bottom-up 방식이 풀기 쉽다.
    ![](./img/2022-03-09-17-19-13.png)

### 1-3. 배열을 이용한 점화식 풀이 방법
![](./img/2022-03-09-17-21-22.png)
- [dp_sequence.cpp](./DynamicProgramming/dp_sequence.cpp)
- 실제 코딩테스트 문제는 `점화식`을 주지 않으니, 직접 유도해야 한다.

### 1-4. 연습문제
- 큰 문제를 작은 문제부터 해결하여 계산하기: 1차원 배열 (대표적인 문제**)
#### 1. 특정 금액을 만들 수 있는 동전의 최소개수를 찾아라
![](./img/2022-03-09-17-39-39.png)
    - 풀이: 20원으로 조합되기 위한 조합의 수는 15원의 조합 + 1 또는 17원의 조합 + 1 의 조합의 수를 갖는다.
    ![](./img/2022-03-09-17-44-42.png)
    - 점화식:
    ![](./img/2022-03-09-17-47-50.png)
    - 배열 설계:
    ![](./img/2022-03-09-18-38-04.png)
    - 코드: [dp_changecoin.cpp](./DynamicProgramming/dp_changecoin.cpp)
        
### 1-5. 실전문제
- 큰 문제를 작은 문제부터 해결하여 계산하기: 2차원 배열 (대표적인 문제**)
#### 1. 가방에 담을 수 있는 보석의 최대 값어치를 담아 훔치자
![](./img/2022-03-09-19-44-08.png)
 - 풀이: 작은 문제들을 풀어나가는 과정을 통해 N=4, K=14 위치의 값을 얻어내자
    ![](./img/2022-03-09-20-15-54.png)
    ![](./img/2022-03-09-20-25-14.png)
    ![](./img/2022-03-09-20-24-47.png)
 - 점화식: 
 ```c++
 if (j >= W)
     DP[i][j] = max(DP[i-1][j], DP[i-1][j-W]+current_price)
     // 배낭의 무게 허용량(j)이 보석의 무게(W)보다 크다면, 새로운 보석을 넣었을 때와 넣지 않았을 때의 max값이 가방에 들어갈 수 있는 보석의 최대값어치이다. 
 else if (j < W)
    DP[i][j] = DP[i-1][j]
    // 보석의 무게(W)가 배낭 허용량(j)보다 무거운 케이스
 ```
 - 코드: [dp_backpack_ruby.cpp](./DynamicProgramming/dp_backpack_ruby.cpp)

#### 2. 주어진 두개의 문자열의 LCS(Longest Common Sequence)를 찾아라
![](./img/2022-03-11-23-34-23.png)
 - 풀이: 작은 문제들을 풀어나가는 과정을 통해 `LCS`를 찾아내자.
 - 문제의 조건에서 `LCS`는 연속적일 문자열일 필요는 없었다.
 - 점화식:
    ![](./img/2022-03-10-23-53-01.png)
    ![](./img/2022-03-10-23-51-44.png)

    ```c++
    vector<vector<int>> DP(A.length()+1, vector<int>(B.length()+1,0));
    string A_token_last;
    for(int i = 1 ; i <= A.length(); ++i){
        A_token_last = A[i-1];
        string B_token_last;
        for(int j = 1 ; j <= B.length(); ++j){
            B_token_last = B[j-1];
            if (A_token_last == B_token_last)
                DP[i][j] = DP[i-1][j-1]+1; 
    //두 문자열의 마지막 문자가 같다면, LCS("A문자열에서 마지막 문자 제거", "B문자열에서 마지막 문자 제거") + 1 의 값의 DP[i][j]의 LCS 최대값
            else
                DP[i][j] = max(DP[i-1][j], DP[i][j-1]);
    //두 문자열의 마지막 문자가 다르다면, max(LCS("A문자열", "B문자열에서 마지막 문자 제거"), LCS("A문자열에서 마지막 문자 제거", "B문자열"))
        }
    }
    ```
 - 코드: [dp_LCS.cpp](./DynamicProgramming/dp_LCS.cpp)



## END & Reference
1. [c언어 문법위키](https://wikidocs.net/book/1411)
