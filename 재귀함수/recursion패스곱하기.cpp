#include <iostream>
using namespace std;

char path[10]; // 예를 char 로 하면 출력이 가능하다
int cnt;

// 얘는 가지치기가 안된다 (누가 가능 하다고 했는데 왜 안쓸지는 아직 잘 모르겠다.)

void run(int lev, int gop)
{
	if (lev == 3)
	{
		if (gop % 2 == 0)
		{
			cnt++;
			return;
		}
	}

	for (int i = 2; i <= 4; i++)
	{
		path[lev] = '0' + i;
		run(lev + 1, gop * i);
		path[lev] = 0;
	}
}

int main()
{
	run(0, 1);
	cout << "짝수인 수 = " << cnt;
}