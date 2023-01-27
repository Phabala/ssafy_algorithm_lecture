#include <iostream>
using namespace std;

void bbq(int x)
{
	if (x == 3)
		return;
	// cout 없이 return 한다면, 얘(3)가 트리 깊이의 length 가 된다.
	// (함수는 4 깊이 까지 실행된다)

	// cout의 위치에 따라
	bbq(x + 1); // 전위 순회
	bbq(x + 1); // 중위 순회
	cout << x;	// 후위 순회

	int dummy = 1;
}

int main()
{
	bbq(0);
}

// 이걸 함수로 만든다면, 세 가지 고려해야 할 상황이 있다.
// 1. 시작점 숫자로써의 파라미터 (bbq(n));
// 2. 몇 깊이까지 탐색 할 것인지 파라미터 (if (x == n) return;)
// 3. 트리 순회 방법 (cout 위치에 따라 전위, 중위, 후위)
