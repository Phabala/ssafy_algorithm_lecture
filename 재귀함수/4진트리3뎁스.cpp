#include <iostream>
using namespace std;

int terminal; // 얘 값은 4^3
int foo[3] = {1, 1, 1};

void bbq(int x)
{
	if (x == 3)
		terminal++;
	return;
	// x말고 아예 이름을 lev로 하는구나

	for (int i = 0; i < 4; i++)
	{
		bbq(x + 1);
	}
}

int main()
{
	bbq(0);
}