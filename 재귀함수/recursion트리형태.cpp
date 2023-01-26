#include <iostream>
using namespace std;

void bbq(int x)
{
    if (x == 2)
        return;
    bbq(x + 1);
    bbq(x + 1);

    int dummy = 1; // 얘는 3번만 읽고 지나간다
}

int main()
{
    bbq(0);
}
