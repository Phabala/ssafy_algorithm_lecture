#include <iostream>
using namespace std;

int x; // 여기서는 x가 0으로 초기화
// cf. 전역변수 쓰는 방법이 있고 안 쓰는 방법이 있는데
// 섞어서 쓰기 금지

void bbq()
{
	if (x == 2)
		return;
	x++;
	bbq();

	int d = 1;
}

int main()
{
	bbq();
}

// 심화

#include <iostream>
using namespace std;

int x = 1;

int recursion()
{
	if (x == 6)
	{
		return 0;
	}

	cout << x;
	x++;
	recursion();
	x--;
	cout << x;
}

int main()
{
	recursion();
}