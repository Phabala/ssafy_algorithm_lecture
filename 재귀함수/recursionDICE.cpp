#include <iostream>
#include <cstring>
using namespace std;

char path[10];
int used[10]; // DAT, 재귀호출 하기 전 이미 나온 눈금인가 조사

void run(int lev) {
    if (lev == 3) {
        cout << path << endl;
        return;
    } 

    for (int i = 0; i <= 6; i++) {
        if (used[i] == 1) continue; // for문의 다음 i로 넘어감
        used[i] = 1; // 내가 i를 쓴다는걸 체크
        path[lev] = '0' + i;
        run(lev + 1);
        path[lev] = 0;
        used[i] = 0;
    }
}

int main () {
    run(0);
}