## 인접행렬 DFS (used 포함)
인접행렬이 아닌, 인접리스트 (이게 뭔소리야)

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> alist(4);
int used[4];

void run(int now) {
    cout << now;
    for (int i = 0; i < alist[now].size(); i++) {
        int next = alist[now][i];
        if (used[next]) continue;
        used[next] = 1;
        run(next);        
    }
}

int main() {
    alist[0] = { 1, 2, 3 };
    alist[1] = { 2, 3 };
    alist[2] = { 3, 0 };

    used[0] = 1;
    run(0);

    return 0;
}
```

## Struct 사용 가중치 인접행렬 DFS
(visited 포함)
```cpp
#include <iostream>
#include <vector>
using namespace std;

struct Node {
	int n;
	int price;
};

vector<vector<Node>> alist(4);
int used[4];
int cnt = 0;

void run(int now, int sum) {
	if (now == 3) {
		cout << sum << endl;
		return;
	}

	for (int i = 0; i < alist[now].size(); i++) {
		Node next = alist[now][i];
		if (used[next.n]) continue;
		used[next.n] = 1;
		run(next.n, sum + next.price);
		used[next.n] = 0;
	}
}

int main() {
	alist[0] = { {1, 5}, {2, 7}, {3, 10} };
	alist[1] = { {2, 2}, {3, 1} };
	alist[2] = { {3, 1}, {0, 90} };

	used[0] = 1;
	run(0, 0);

	return 0;
};

```cpp