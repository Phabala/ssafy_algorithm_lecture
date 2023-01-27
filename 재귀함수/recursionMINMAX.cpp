#include <iostream>
using namespace std;

// 각 라인 별 최솟값, 최대값 출력

int map[4][4]{
    3, 1, 4, 2,
    1, 1, -1, 1,
    2, 3, 1, 4,
    5, 1, 0, 3};

int maxi = -21e8; // -21억
int mini = 21e8;  // 21억

void run(int lev, int gop)
{
    if (lev == 4)
    {
        if (maxi < gop)
            maxi = gop;
        if (mini > gop)
            mini = gop;
        cout << gop << " ";
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        run(lev + 1, gop * map[lev][i]);
    }
}

int main()
{
    run(0, 1);
    cout << maxi << endl;
    cout << mini << endl;
}