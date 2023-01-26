#include <iostream>
using namespace std;

int recursion(int a)
{
	if (a == 4)
	{ // 기저조건
		return 0;
	}

	cout << a << " ";

	// 트리구조 횟수로 출력
	recursion(a + 1); // 일단 내 박스는 stop, 따라서 0122122 로 출력됨
	recursion(a + 1);
}

int main()
{
	recursion(0);
}

// 1. 규칙찾기, 2. 기저 조건 설정, 3. 하고 싶은 일 처리 (신경써야 할건 여섯가지)