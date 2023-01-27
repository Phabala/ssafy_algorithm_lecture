#include <iostream>
#include <cstring>
using namespace std;

// 조합과 순열의 차이 (중복 여부도)
// 이거는 중복 조합

char path[10];

void run(int lev, int start)
{
    if (lev == 2)
    {
        cout << path << '\n';
        return;
    }

    for (int i = start; i <= 6; i++)
    {
        path[lev] = '0' + i;
        run(lev + 1, i);
        path[lev] = 0;
    }
}

int main()
{
    run(0, 1);
}