#include <iostream>
using namespace std;

char path[4];

void run(int lev)
{
	if (lev == 4)
	{
		cout << path[0] << path[1] << path[2] << path[3] << endl;
		return;
	}

	for (char i = 'A'; i <= 'Z'; i++)
	{
		path[lev] = i;
		run(lev + 1);
		path[lev] = 0;
	}
}

int main()
{
	run(0);
}