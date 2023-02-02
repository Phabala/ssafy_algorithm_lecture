## BFS 를 써야할 경우
DFS는 가중치 그래프, 모든 경로 탐색 등에 좋다.
BFS는 최소 경로 탐색 등에 좋다. (BFS는 최소 경로를 탐색한 다음에 종료 해버리면 된다.)
(속도는 똑같다고 보는데, 메모리가 다르다)

## BFS 인접행렬
```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int arr[5][5] = {
    0,1,0,0,1,
    0,0,1,1,0,
    0,0,0,0,0,
    0,0,0,0,0,
    0,0,0,0,0,
};

char name[6] = "ACTSB";

queue<int> q;

int main() {
    
    //1. 초기세팅
    q.push(0);

    while (!q.empty()) {

        //1. 큐에서 하나 뺀다.
        int now = q.front(); 
        q.pop();

        cout << name[now];

        //2. 연결된거 찾아 큐에 넣기
        for (int i = 0; i < 5; i++) {
            if (arr[now][i] == 0) continue;
            q.push(i);
        }

    }

    return 0;
}
```
## BFS 인접 링크드 리스트
```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> aList = {
    {1, 4}, {2, 3}, { }, { }, { }
};

char name[6] = "ACTSB";

queue<int> q;

int main() {

    //1. 초기세팅
    q.push(0);

    while (!q.empty()) {

        //1. 큐에서 하나 뺀다.
        int now = q.front();
        q.pop();

        cout << name[now];

        //2. 연결된거 찾아 큐에 넣기
        for (int i = 0; i < aList[now].size(); i++) {
            int next = aList[now][i]);
            q.push(next);
        }

    }

    return 0;
}
```
## 최소 경로 탐색 (레벨, struct, 링크드리스트 활용)
```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct Node {
    int n;
    int lev;
};

vector<vector<int>> alist(5);
int used[5];
queue<Node> q;

int main() {

    alist[0] = { 1, 2, 3 };
    alist[1] = { 2, 3 };
    alist[2] = { 3 };
    alist[3] = { 4 };

    q.push({ 0, 0 });
    while (!q.empty()) {
        Node now = q.front();
        q.pop();

        if (now.n == 4) {
            cout << now.lev;
            break;
        }

        for (int i = 0; i < alist[now.n].size(); i++) {
            int next = alist[now.n][i];
            if (used[next]) continue;
            used[next] = 1;
            q.push({next, now.lev + 1});
        }
    }

    return 0;
}
```