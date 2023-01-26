#include <iostream>
using namespace std;

char map[4][5] = {
    '_',
    '_',
    '_',
    '_',
    '_',
    '_',
    '_',
    '_',
    '_',
    '_',
    '_',
    '_',
    '_',
    '_',
    '_',
    '_',
    '_',
    '_',
    '_',
    '_',
};

void bomb(int y, int x)
{
    int d[8][2] = {
        1, 1,
        1, 0,
        1, -1,
        0, -1,
        0, 1,
        -1, -1,
        -1, 0,
        -1, 1};

    int dy, dx;

    for (int i = 0; i < 8; i++)
    {
        dy = y + d[i][0];
        dx = x + d[i][1];

        if (dy >= 0 && dy < 4 && dx >= 0 && dx < 5)
        {
            map[dy][dx] = '#';
        }
    }
}

int main()
{
    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;
    bomb(y1, x1);
    bomb(y2, x2);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}