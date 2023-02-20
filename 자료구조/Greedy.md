# 그리디 (Greedy)
예전에는 이게 무슨 알고리즘이냐 이런 소리가 나왔었는데, 분류하기 위해 등장한 알고리즘이다.

**DP (Dynamic)** 지게차 문제
밟은 만킄 타이어가 마모된다.
최소로 마모되게 

만능 방법: Backtracking
단점: 느리다.

END 지점에서부터 이전 에서부터 나온 정답으로 그 다음 값을 구하는 방식.

**Greedy**: 미래를 생가갛지 않고, 지금 상태에서 좋은 값을 선택한다.
단점: 정답이 안 나올 수 있다. (수학적 검증이 필요, 거의 못한다고 봐야함)
N이 10만에서 10만이면 그리디스럽다고 생각하자. (수학)
규칙을 찾아야 한다. 1. 그리디 2. DP (1은 무식 2는 똑똑한 방식)
그리디는 그냥 많이 풀어야한다. 30개정도의 유형 풀면 왠만한 그리디는 다 정복한 거다.
그리디로 풀었던 기억이 나면 그게 그리디다.
DP가 뭔지 알고 그에 반하는게 그리디다.
그리디 문제 풀기 위해서는 그리디 30개정도 풀어보면 끝이다.

**알고리즘탑 Greey 동전교환**
동전을 많이 거슬러 주면 안된다. 동전을 최소로 거슬러 줄 수 있는 갯수는?
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

// 거스름돈 예시
/*
1500 4
100 50 10 500
*/

bool cmp(int left, int right) {
    if (left > right)
        return true;
    if (left < right)
        return false;
    return false; 
}

int target; // 거스름돈
int N; // 동전의 수
int coins[5]; 

int main() {
    cin >> target;
    cin >> N; 
    // 동전 입력 
    for (int i = 0; i < N; i++)
        cin >> coins[i]; 

    // S : 탐욕적으로 가장 큰 단위의 동전부터 돌려준다! 
    sort(coins, coins + N, cmp); 

    int ans = 0; 
    for (int i = 0; i < N; i++) {
        int now = coins[i]; 
        ans += target / now; 
        target %= now; 
    }
    cout << ans; 
}
```

**경험론적인 힌트**
그리디 문제의 70~80%는 Sort로 시작한다.
N값이 10만개가 나오면 Sort를 연상해보면 좋다.