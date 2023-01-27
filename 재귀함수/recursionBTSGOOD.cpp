#include <iostream>
using namespace std;

char name[10] = "BTSGOOD";
char path[3];

void run(int lev)
{
    if (lev == 3)
    {
        cout << path << endl;
        return;
    }

    for (int i = 0; i < 7; i++)
    {
        path[lev] = name[i];
        run(lev + 1);
        path[lev] = 0;
    }
}

int main()
{
    run(0);
}