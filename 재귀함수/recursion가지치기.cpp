#include <iostream>
using namespace std;

char path[3]; // 예를 char 로 하면 출력이 가능하다

void run(int lev, int sum)
{
	if (lev == 3)
	{
		if (sum <= 10)
		{
			cout << path << " = " << sum << endl;
			// 1. 여기에 return 을 넣어서 가지치기를 하거나 (10 이하면)
		}
		return;
	}

	for (int i = 1; i <= 6; i++)
	{
		if (sum + i > 10)
			continue; // 2. 여기에 10 이상인것만 넣어서 가지치기를 하거나
		// 속도는 거기서 거기다, 그러니 편한대로 하자. (둘 다 연습하자, 문제마다 편한게 다르기 때문
		path[lev] = '0' + i;
		run(lev + 1, sum + i);
		path[lev] = 0;
	}
}

int main()
{
	run(0, 0);
}