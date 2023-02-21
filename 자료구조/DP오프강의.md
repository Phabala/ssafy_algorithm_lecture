# DP

**기존 구했던 정답을 이용해서 현재의 정답을 구하는 방식**
*예시: 피보나치 수열*

두가지 방식이 있다.
배열에 기입하는 방식 : Bottom - Up
재귀호출 돌리는 방식 : Top - Down
배열에 기입하면 바텀업, 재귀를 하면 Top-Down

둘 다 연습해서 떠오르는 걸로 하면 된다.
그래서 우리는 연습 시간에 한 문제를 두번 풀 것이다.

## Bottom-Up 코드
**Tabulation**
피보나치는 바텀업이 더 쉽다.
```cpp
#include <iostream>
using namespace std;

int main() {
    int arr[10] = {0, 1};
    for (int i = 2; i < 10; i++) {
        arr[i] = arr[i - 2] + arr[i - 1];
    }

    return 0;
}
```

바텀업으로 구현할거면 DP 테이블을 A4에 써서 다 손으로 써놨어야 한다.
그래서 디버깅 할 때 그걸 눈으로 보면서 같은지 확인해야 한다.
DP 설계는 인내가 필요하다. 짜는건 금방 짜는데 설계가 오래 걸린다.

## Top-Down 코드
**Memoization**
메모이제이션을 안쓰면 DP라고 보기 어렵다.
*백트래킹을 한건데 이미 작동했던 함수 작동 안하려고 그냥 가지치기를 한거라고 볼 수도 있다.*

| NUM | 0 | 1 | 2 | 3 | 4 | 5 | 6 |
| --- | - | - | - | - | - | - | - |
| ANS | 0 | 1 | 1 | 2 | 3 | 5 | 8 |

```cpp
#include <iostream>
using namespace std;

int memo[100]; // 메모장

int fib(int index) {
    if (memo[index] != 0) return memo[index];

    if (index == 1) return 1;
    if (index == 0) return 0;

    int a = fib(index - 1); // 이렇게 하면 디버깅이 편하다.
    int b = fib(index - 2);

    memo[index] = a + b;
    return a + b;
}
```
fib함수는 다 완성한 상태에서, 성능을 올리기 위해 memo를 추가하면 좋다.

## 동전교환 코드
동전교환 코드는 탑다운이 더 쉽다.
### Top-Down 코드
```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int getMin(int price) {
    if (price < 0) return 21e8;
    if (price == 0) return 0;

    int a = getMin(price - 10) + 1; // 90원일 때 정답 (최소개수) a에 저장됨.
    int b = getMin(price - 50) + 1; // 50원일 때 정답
    int c = getMin(price - 70) + 1; // 70원일 때 정답

    int result = min(min(a, b), c);
    return result;
}

int main() {
    int ret = getMin(100);
    cout << ret << "개";

    return 0;
}
```