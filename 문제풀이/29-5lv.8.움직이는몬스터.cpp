#include <iostream>
#include <vector>
using namespace std;

char map[4][3];
char names[3];

int direct[4][2] = {
    0, 1, // Right
    1, 0, // Down
    0, -1, // Left
    -1, 0 // Up
};

struct Monster {
    char name;
    int y;
    int x;

    // 본인의 이름과 같은 문자열이 MAP 상에 있으면 y와 x값을 넘겨받는 함수 (이름이 먼저 설정되있어야 한다.)
    void getPos() { 
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (map[i][j] == this->name) {
                    this->y = i;
                    this->x = j;
                    return;
                }
            }
        }
    }

    void moveRight() {
        int dy = direct[0][0];
        int dx = direct[0][1];
        int after_y = this->y + dy;
        int after_x = this->x + dx;

        if (after_y >= 0 && after_y <= 3 && after_x >= 0 && after_x <= 2 && map[after_y][after_x] == '_') {
            map[this->y][this->x] = '_';
            map[after_y][after_x] = this->name;
            this->y = after_y;
            this->x = after_x;
        }
        else {
            return;
        }
    }

    void moveDown() {
        int dy = direct[1][0];
        int dx = direct[1][1];
        int after_y = this->y + dy;
        int after_x = this->x + dx;

        if (after_y >= 0 && after_y <= 3 && after_x >= 0 && after_x <= 2 && map[after_y][after_x] == '_') {
            map[this->y][this->x] = '_';
            map[after_y][after_x] = this->name;
            this->y = after_y;
            this->x = after_x;
        }
        else {
            return;
        }
    }

    void moveLeft() {
        int dy = direct[2][0];
        int dx = direct[2][1];
        int after_y = this->y + dy;
        int after_x = this->x + dx;

        if (after_y >= 0 && after_y <= 3 && after_x >= 0 && after_x <= 2 && map[after_y][after_x] == '_') {
            map[this->y][this->x] = '_';
            map[after_y][after_x] = this->name;
            this->y = after_y;
            this->x = after_x;
        }
        else {
            return;
        }
    }

    void moveUp() {
        int dy = direct[3][0];
        int dx = direct[3][1];
        int after_y = this->y + dy;
        int after_x = this->x + dx;

        if (after_y >= 0 && after_y <= 3 && after_x >= 0 && after_x <= 2 && map[after_y][after_x] == '_') {
            map[this->y][this->x] = '_';
            map[after_y][after_x] = this->name;
            this->y = after_y;
            this->x = after_x;
        }
        else {
            return;
        }
    }
};

void getNames() {
    // names 전역 배열에 몬스터 이름 넣기
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (map[i][j] >= 'A' && map[i][j] <= 'Z') {
                names[cnt++] = map[i][j];
            }
        }
    }

    // 이름 순서에 맞게 정렬
    for (int t = 2; t > 0; t--) {
        for (int i = 0; i < t; i++) {
            if (names[i] > names[i + 1]) swap(names[i], names[i+1]);
        }
    }
}

int main() {

    // 1. MAP을 입력 받는다
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> map[i][j];
        }
    }

    // 몬스터들의 이름 얻기
    getNames();

    // 몬스터 선언 및 몬스터 이름 선언
    Monster monster1, monster2, monster3;

    monster1.name = names[0];
    monster2.name = names[1];
    monster3.name = names[2];

    // getPos 함수로 몬스터들의 인덱스 받기
    monster1.getPos();
    monster2.getPos();
    monster3.getPos();

    // 5초 동안 순서에 맞게 몬스터 움직이기
    monster1.moveRight();
    monster2.moveRight();
    monster3.moveRight();

    monster1.moveDown();
    monster2.moveDown();
    monster3.moveDown();

    monster1.moveLeft();
    monster2.moveLeft();
    monster3.moveLeft();

    monster1.moveUp();
    monster2.moveUp();
    monster3.moveUp();

    monster1.moveRight();
    monster2.moveRight();
    monster3.moveRight();

    // 5초 후 map 출력
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            cout << map[i][j];
        }
        cout << endl;
    }
}

// 개발 전 설계
// 1. 몬스터들의 위치를 입력 받는다
// (추가) 몬스터의 이름들을 얻어와, 이름들을 Sort한다. 그리고 Monster 1, 2, 3들에게 순서대로 이름을 부여한다.
// 2. 몬스터의 알고리즘을 작성한다
// 2-1. struct 안에 메소드를 작성한다
// 2-2. struct 안의 메소드: moveRight, moveDown, moveLeft, moveUp 을 설계하고, 
// 오른쪽 아래 왼쪽 위 오른쪽 순서로 작동시킨다.
// 메소드 설계는 다이렉트를 이용하며, if 문을 사용해 이동할 방향의 char 가 '_'가 아니거나, 
// [4][3] 범위 밖에 있는 경우 움직이게 하지 않는다.