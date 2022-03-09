# Coding Test Prepare with c/c++
- INFLEARN LECTURE: IT 기업 취업을 위한: 코딩 테스트 혼자서 정복하기 (26,400원)
- Writer: Sungwook LE
- DATE: '22.3/9~
- LANGUAGE: `C++`
- 목표:
    1. 문제가 요구하는 알고리즘을 파악할 수 있다.
    2. 최소한의 문법으로 최대한 깔끔한 코드를 작성할 수 있다. 
    3. 공통적으로 출제되는 문제의 **템플릿**을 작성/이해하고 이를 통해 문제를 풀자.


## 1. 동적 프로그래밍과 점화식의 관계
- Dynamic Programming = **분할정복 프로그래밍**
- 분할정복 풀이: `Bottom-up` 방식으로 풀자
    - 문제를 직접 풀려고 `if`문을 생각하게 되면, 여러 예외조건에 막혀 문제를 풀 수 없게된다는 것을 명심
  
- 분할정복 풀이를 위한 **점화식**(`recurrence relation`)
    1. 수열의 n번째 값 $a_n$을 구하기 위해 따라야 하는 규칙
    2. $a_n$을 구하기 위해서는, $a_1$부터 순서대로 계산해야 함

- 생각하기
    - 점화식이 아래와 같을 때, $a_5$를 구하여라.
        - $a_1 = 3$ 
        - $a_n = 2a_{n-1}-4$

    - Solution: Bottom-up 접근
    Note: Top-down 방식으로 풀어야하는 문제도 있으나, 대부분 Bottom-up 방식이 풀기 쉽다.
        ![](./img/2022-03-09-17-19-13.png)

- 개념연습
    ![](./img/2022-03-09-17-21-22.png)
    - [dp_sequence.cpp](./DynamicProgramming/dp_sequence.cpp)
    - 실제 코딩테스트 문제는 `점화식`을 주지 않으니, 직접 유도해야 한다.

- 연습문제
    1. 큰 문제를 작은 문제부터 해결하여 계산하기: 1차원 배열
    ![](./img/2022-03-09-17-39-39.png)
        - 풀이: 20원으로 조합되기 위한 조합의 수는 15원의 조합 + 1 또는 17원의 조합 + 1 의 조합의 수를 갖는다.
        ![](./img/2022-03-09-17-44-42.png)
        - 점화식:
        ![](./img/2022-03-09-17-47-50.png)
        - 배열 설계:
        ![](./img/2022-03-09-18-38-04.png)
        - 코드: [dp_changecoin.cpp](./DynamicProgramming/dp_changecoin.cpp)
        

    



    
## Reference
1. [c언어 문법위키](https://wikidocs.net/book/1411)