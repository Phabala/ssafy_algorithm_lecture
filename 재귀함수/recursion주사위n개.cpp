#include <iostream>
using namespace std;

int n;
char path[100];
int visited[7]; // index : 주사위 눈, value : 해당 주사위 눈을 뽑았었는가? <-- DAT 를 활용하고 있음
// n 은 전역변수로 놓아도 된다

void func(int a) // 앞에서 나온 주사위 눈은 안 뽑는 함수
{
    // 지금 a번째 주사위 눈을 뽑을 차례

    // 2. 기저 조건
    //  0~N-1 번 주사위까진 정상
    //  N번 주사위부터는 존재하지 않는 주사위
    //  N번 주사위까지 왔다 => 0~N-1 번 주사위에선 모두 눈을 뽑았다.
    if (a >= n)
    {
        // if (같은 눈을 뽑은 기록이 없으면) {
        //    for (int i = 0; i < n; i++) {
        //        cout << path[i] << " " << endl;
        //      }
        // }
        return;
    }

    // i : 1~6이라는 눈
    for (int i = 1; i <= 6; i++)
    {

        // 4. 가지치기 (내가 지금 하려는 선택이 괜찮은가?)

        // i라는 눈을 이번에 뽑고 싶은데, 괜찮은가?
        if (visited[i] == 1)
        {             // i라는 눈은 이미 뽑혔다.
            continue; // i라는 눈을 스킵하고 다음 눈으로 넘어가라
            // 괜찮으면 뽑아가자

            // 3. '기록 및 처리'
            path[a] = i;
            visited[i] = 1; // i라는 눈은 뽑았다.

            // 4. ~~~~~~~~ <- 여기서 판단해봐야 하는 경우도 있음

            // 1. 재귀 기본 구조
            // a+1 번째 주사위에서 눈을 뽑으러 가라!
            func(a + 1);

            // i라는 눈을 뽑아서 진행하는 과정이 모두 끝났다.
            // i라는 눈은 사요이 끝났으므로, 그에 따른 기록을 삭제
            visited[i] = 0; // i라는 눈에 대한 기록 삭제
            path[a] = 0;    // a번째 주사위에서 i라는 눈을 뽑은 기록 삭제
        }
    }
}

void run(int lev, int n)
{
    if (lev == n)
    {
        cout << path << endl;
        return;
    }

    for (char i = '1'; i <= '6'; i++)
    {
        path[lev] = i;
        run(lev + 1, n);
        path[lev] = 0;
    }
}

int main()
{

    cout << "주사위의 개수 입력 (100이하) : ";
    cin >> n;
    run(0, n);
}

// int path[10]; index: 주사위 번째, value : 해당 주사위에서 어떤 눈을 뽑았는가?
// int visited[7]; // index : 주사위 눈, value : 해당 주사위 눈을 뽑았었는가? (0 : 안뽑음, 1 : 뽑음)
// visited, used 면 대부분 이 이름이다. (check 는 거의 안씀)
