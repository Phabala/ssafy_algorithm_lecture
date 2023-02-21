# DP (Dynamic Programming)

**답을 기억하는 프로그래밍 기법**
이름에는 아무 뜻도 없다.
`<img src="./../images/DP.png">`

## 피보나치 수열 구하기

```cpp
#include <iostream>
using namespace std;

int fibo(int now) { 		// N번째 피보나치를 구하는 프로그램
	if (now <= 2) return 1;	// 기저조건
				// 재귀구성
				// now = now - 1 + now - 2
	return fibo(now - 1) + fibo(now - 2);
}
```

`<img src="./../images/피보나치.png">`

만약 `fib(n)`의 값을 이미 알고 있다면, 함수 호출을 다시 안 해도 될 것이다.

***DAT를 사용하여 해결하자***

**다이나믹 프로그래밍: 기억하기 프로그램**

```cpp
#include <iostream>
using namespace std;

int dp[101];

int fibo(int now) {
	if (now <= 2) return 1;
	if (dp[now] != 0) return dp[now]; // 재귀 구성: 다시 여기까지 돌아오는 순간은 now의 정답을 찾은 순간
	return fibo(now - 1) + fibo(now - 2);
}

int main() {
	cout << fibo(10);
}
```

`return fibo(now - 1) + fibo(now - 2);`

이 코드 블럭을 점화식이라고 하는데, 실전에서 이를 연상하고 사용하기는 꽤나 까다롭다.

## DP를 푸는 방법 두가지

1. Top - Down
2. Bottom - Up

### 1. Top - Down

피보나치를 예시로 든다면

fib(5) -> fib(4) -> fib(3) -> fib(2) -> fib(1) -> return fib(1) -> return fib(2) -> return fib(3) -> return fib(4) -> return fib(5)

위의 코드 예시가 탑다운 방법이다.

### 2. Bottom - Up

아래에서부터 시작.

우리가 풀 수 있는 가장 작은 문제부터 시작하여 그 위로 올라가며 문제를 푼다.

| num | 1 | 2 | 3 | 4 | 5 | 6 |
| --- | - | - | - | - | - | :-: |
| ans | 1 | 1 | 2 | 3 | 5 | 8 |

테이블을 채워간다고 해서 이 방법을 `Tabulation`이라고 한다.

탑다운이 정석적인 방법이라면 바텀업은 조금 더 빠르게 푸는 방법.

> Bottom - Up (Tabulation)
> 아래의 (가장 하위의 문제)부터 순차적으로 더 상위 문제를 해결해나감.
> 점화식을 생성할 수 있어야 한다.
> 가장 작은 문제에 대한 해답을 구해야한다.


```cpp
#include <iostream>

int main() {
	int N;
	cin >> N;

	if (dp[N] != 0) cout << dp[N];

	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= N; i++) {
		dp[i] = dp[i - 2] + dp[i - 1];
	}

	cout << dp[N];
}
```

## 거스름돈 예제

```cpp
#include<iostream>
using namespace std;

// 거스름돈 
/*
1200 5
500 400 100 50 10
*/

// Memoization (Top-Down)
// - 정석적인 방법 (재귀 동작에 대한 이해도가 있다) 
// - 아마 이 방법이 설계하기 더 쉽다. 
// - 가지치기, backtracking, return 조건 이런것만 생각하고 구성
//   아주 조건이 까다로워도 생각보다 코드 짜는게 어렵지 않을것. 
// - 재귀 호출 + return 취합 -> tabulation보다는 비교적 느림
// - 모든 문제를 풀지 않음 (내가 풀어야 하는 문제만 푼다.) 

// Tabulation (Bottom-Up)
// - 점화식 구성이 필요하므로 상대적으로 쉽게 구성 X 
// - 점화식 구성에 조건이 까다로우면 점화식 만들기도 쉽지 않다. 
// - 최하위 문제로부터 N까지 모든 문제를 푼다. 


// index : 특정 거스름돈 액수
// value : 그 거스름돈을 돌려주기 위한 최소 동전 개수
int dp[10001];
int target; // 만들어야 하는 거스름돈 
int N; 
int coins[100]; 

// #1. Top-Down
int func(int now) {
    // 기저 조건(base case) 
    if (now == 0) //답을 찾았다!
        //정답에 영향을 주지 않는 값 return 
        return 0; 

    if (now < 0) // 오답이다! 
        //now까지의 기록에 최소값이 저장될 수 있도록
        // 영향을 미칠 값 즉, 아~주 큰 값을 return
        return 21e8; 

    // 만약 now에 대한 답이 기억(기록)되고 있다면 
    if (dp[now] != 0)
        return dp[now];

    // 재귀 구성(recursive case)
    // now에서 모든 동전을 하나씩 빼가면서 쭉 쭉 내려가본다
    int MIN = 21e8; 
    for (int i = 0; i < N; i++) {
        // now로 다시 올라오면 
        // func(now-coins[i]) + 1 
        int temp = func(now - coins[i]) + 1;
        // 이 temp가 최소인가? 
        if (temp < MIN)
            MIN = temp; 
    }

    // now까지 올라왔을때, 하위 문제의 답을 모두 취합하여
    // 그 중 가장 작은 값을 dp[now]에 기록 
    return dp[now] = MIN;
}

int main() {
    cin >> target >> N;
    for (int i = 0; i < N; i++)
        cin >> coins[i]; 
    // cout << func(target);

    // Bottom-Up
    // #0. 최소값
    for (int i = 0; i <= target; i++)
        dp[i] = 21e8; 
    // #1. 찾을 수 있는 가장 작은 문제에 대한 해답 
    dp[0] = 0; 

    // 모든 코인에 대해서 테이블을 채운다
    for (int i = 0; i < N; i++) {
        int now = coins[i]; 
        for (int j = now; j <= target; j++) {
            // 지금 위치에서 내 동전의 값만큼을 뺀 공간에서
            // 동전을 하나 더 추가했을때 -> 지금 now를 만들 수 있는 값이 나온다
            // 이미 dp에 기록된 값보다 많은 개수로 만들게 된다면 -> 갱신 X
            if (dp[j - now] + 1 < dp[j])
                dp[j] = dp[j - now] + 1; 
        }
    }
    cout << dp[target];
}
```

## 정리

**Memorization (Top-Down)**

- 정석적인 방법 (재귀 동작에 대한 이해도가 있다.)
- 아마 이 방법이 더 설계하기 더 쉽다.
- 가지치기, backtracking, return 조건 이런것만 생각하고 구성하면 아주 조건이 까다로워도 생각보다 코드 짜는게 어렵지 않다.
- 재귀호출 + return 취합 등의 과정 때문에 tabulation보다는 비교적 느리다.
- 모든 문제가 풀리지 않을 수 도 있다. (일부 조건을 누락하지 않도록 조심해야 한다.)

**Tabulation (Bottom-Up)**

- 점화식 구성이 필요하므로 상대적으로 구성하는 방법이 더 까다롭다.
- 점화식 구성에 조건이 까다로우면 점화식 만들기도 쉽지 않다.
- 최하위 문제로부터 N까지 모든 문제를 푼다.
