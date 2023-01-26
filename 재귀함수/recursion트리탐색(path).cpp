#include <iostream>
using namespace std;

int path[2];

void run(int lev)
{
    if (lev == 2)
        return;
    // x말고 아예 이름을 lev로 하는구나

    for (int i = 0; i < 3; i++)
    {
        path[lev] = i + 1; // 적고 안으로 재귀하기
        run(lev + 1);
        path[lev] = 0; // 방금 적은거 지우기 (안 지워도 되긴 하는데)
    }
}

int main()
{
    run(0);
}