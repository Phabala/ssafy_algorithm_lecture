#include <stdio.h>

char input[110000];
char dat[200];

int main()
{
    // freopen("Text.txt", "r", stdin);
    scanf("%s", input); // 그냥 한번에 인풋 받아도 된다
    // cin >> input;

    for (int i = 0; input[i]; i++)
    { // input[i] 값이 '\0' 이면 종료
        dat[input[i]] = 1;
    }

    for (int i = 0; i < 200; i++)
    {
        if (dat[i] == 0)
            continue;
        printf("%c", i);
        // cout << (char)i;
    }

    return 0;
}