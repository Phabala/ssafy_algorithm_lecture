#include <iostream>
using namespace std;
int win[2][3] = {3, 5, 1, 4, 2, 6};

int main()
{
	int cnt_people[10] = {0};
	int cnt_win[10] = {0};

	int people[4];
	for (int i = 0; i < 4; i++)
	{
		cin >> people[i];
		cnt_people[people[i]]++;
	}

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cnt_win[win[i][j]]++;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		if (cnt_people[i])
		{
			if (cnt_win[i])
			{
				cout << i << "번 합격" << endl;
			}
			else
			{
				cout << i << "번 불합격" << endl;
			}
		}
	}
}