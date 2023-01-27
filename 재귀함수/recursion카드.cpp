#include <iostream>
#include <cstring>
using namespace std;

char card[5] = {'A', 'G', 'K', 'R', 'P'};

int used[10];
char path[4];

void run(int lev)
{
    if (lev == 4)
    { // 4레벨까지 들어가면
        for (int i = 0; i < 5; i++)
        {
            cout << path[i]; // used를 사용해서 출력하면, 순서 상관없이 나온다. 정답은 path로 출력 하는게 맞다
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < 5; i++)
    {
        if (used[i])
            continue;        // 사용한 i를 체크한다
        path[lev] = card[i]; // path 레벨에 care[i]를 저장한다
        used[i] = 1;         // 사용한 i를 저장한다
        run(lev + 1);        // 다음 레벨로 들어간다
        used[i] = 0;
        path[lev] = 0;
    }
}

int main()
{
    run(0);
}

/*
for (int i = 0; i < 5; i++) {
    if (used[i]) continue; // 사용한 i를 체크한다
    path[lev] = i + 1; // path 레벨에 i + 1을 저장한다
    used[i]++; // 사용한 i를 저장한다
    run(lev + 1); // 다음 레벨로 들어간다
    used[i] = 0;
    path[lev] = 0;
}
*/