# Flood Fill

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int arr[3][3];
struct Node {
    int y, x;
};
queue<Node> q;
int directY[4] = { -1, 1, 0, 0 };
int directX[4] = { 0, 0, 1, -1 };

int main() {

    arr[0][0] = 1;
    q.push({ 0, 0 });

    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        //다음 갈수있는곳을 큐에 등록
        for (int t = 0; t < 4; t++) {
            int ny = now.y + directY[t];
            int nx = now.x + directX[t];
            if (ny < 0 || nx < 0 || ny >= 4 || nx >= 4) continue;
            if (arr[ny][nx] != 0) continue;

            arr[ny][nx] = arr[now.y][now.x] + 1;
            q.push({ ny, nx });
        }
    }

    return 0;
}
```
