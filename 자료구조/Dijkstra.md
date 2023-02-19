# 다익스트라
`Dijkstra` 의 의미: 사람 이름 (네덜란드 컴퓨터과학자)
**최단 거리를 찾는 알고리즘**

- 가중치가 없고, 최단경로를 찾을 때는 BFS 사용
- 가중치가 있고, 최단거리를 찾을 때는 Dijkstra 사용
  
> - 추가로 알면 좋은 것: Floyd Warshall: 모든 노드로부터 모든 노드 까지의 최단거리
> - Belman-Ford : 음수 가중치
> 코테를 위해 굳이 깊게 할 필요는 없다. 안나오는 경우가 많음.

핵심: 가중치가 가장 작은것 위주로 골라서 간다

# 풀이법

## 준비 단계

1. dist DAT 필요 -> dist[출발지] = 0
2. visited 필요 (지금 이 노드의 최단 거리가 확정이 되었나)

## 구현 단계
1. 모든 노드의 최단거리가 확정될 때 까지 
2. 지금 dist에 기록되어있는 후보 거리 중 가장 작은 간선을 노ㄷ로 찾는다.
(이 노드로 간다 = 이 노드의 최단 거리는 확정된다!)
3. now번 노드로부터 갈 수 있는 모든 간선들을 확인하면서 dist에 후보지를 갱신
   - 만약 이미 가진 후보지보다 작거나 같은 경로가 나타나면 갱신할 필요 X

나의 구현 시도
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int dist_DAT[10];
int visited[10];

// alist 어떻게 쓰더라. alist로 입력 받고 sum에 그 값을 추가 해야 하는데

int DFS(int lev, int sum, int destination) {
	if (lev == destination) {
		if (dist_DAT[destination] > sum) dist_DAT[destination] = sum;
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (visited[i] == 1) continue;
		visited[lev] = 1;
		DFS(lev + 1, sum, destination);
		visited[lev] = 0;
	}
}

// 인접 매트릭스 말고 인접 리스트를 어떻게 쓰더라?
int main()
{

}
```
유튜브 코드
```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
/*
10 13
0 1 1
0 3 4
0 2 5
1 4 3
1 5 6
2 5 8
2 7 10
2 6 9
7 6 11
6 9 2
6 8 13
7 8 12
5 6 7
*/
struct Edge {
	int to; // 어디로 향하는 간선이고?
	int cost; // 가중치
	bool operator< (Edge next) const {
		// 내가 원하는 상황 
		if (cost < next.cost)
			return false;
		if (cost > next.cost)
			return true;
		// 항상 무지성 false 
		return false; 
	}
};
int N, M; // N : 노드의 개수, M : 간선의 개수
vector<Edge>al[100]; 
// 시간복잡도 : O(V^2)
void dijkstra_for(int start) {
	// dist 준비
	int dist[100] = { 0, };
	// 모두 아주 큰 값이 들어가도록 세팅
	int MAX = 21e8; 
	for (int i = 0; i < N; i++)
		dist[i] = MAX; 
	// 출발지까지는 가중치 = 0
	dist[start] = 0; 
	// visited 준비
	// index: 노드, value: 지금 이 노드의 최단 거리가 확정이 되었는가? 
	int visited[100] = { 0, }; 
	// dijkstra 동작을 구현 
	// 노드의 개수만큼 반복 -> 한번 돌때마다 하나의 노드의 최단 거리가 확정
	// 즉, 모든 노드의 최단거리가 확정될때까지 
	for (int i = 0; i < N; i++) {
		int mincost = 21e8; // 지금 가장 작은 가중치를 가진 간선의 값
		int now = -1; // 내가 지금 가려고 하는 노드 
		// 지금 가장 가중치가 작은 간선을 찾을것 
		for (int j = 0; j < N; j++) {
			// j번째 노드에 기록된 후보지가 최소값보다 작으면 -> 갱신 
			if (dist[j] >= mincost)
				continue; 
			// 이미 확정된 노드라면 -> 다시 갈 필요 X
			if (visited[j] == 1)
				continue; 
			// 새로운 최소값을 찾았다! 
			mincost = dist[j];
			now = j; 
		}
		// now까지의 최단 거리 = 확정
		visited[now] = 1; 
		for (int j = 0; j < al[now].size(); j++) {
			Edge next = al[now][j]; 
			// 다음 노드까지의 비용 = 지금 확정된 노드까지의 비용(거리) + next까지 가는 비용
			int ncost = dist[now] + next.cost; 
			// 새로운 경로를 찾았다
			// 하지만, 이미 기록된 후보지보다 더 오래걸리는 경로면 쓸모 없다 
			if (dist[next.to] <= ncost)
				continue; // 새로운 후보지로 등록하지 않는다. 
			dist[next.to] = ncost; 
		}
	}
	for (int i = 0; i < N; i++) {
		cout << i << " 까지의 최단 거리 : " << dist[i] << '\n';
	}
}
/*
** Dijkstra는 인접 리스트로 구성 
준비 단계
#1. priority queue 준비
->시작 Edge를 일단 삽입(시작 노드, 0)
#2. dist 준비
->모두 아주 큰값으로 채운 후
->시작 노드까지의 최단 거리를 초기값 설정(0)
#3. visited 준비
구현 단계
#1. 더이상 갈 후보지가 없을때까지 반복
#2. 가장 가중치가 작은 간선 채택 -> (top) = now
->이 노드를 확정!
#3. now로부터 갈수 있는 간선들 확인하면서
->dist 기록 갱신
->pq에 후보지 삽입
*/
// PQ를 사용한 dijkstra 시간복잡도 : 
// 최소 모든 간선 한번씩 : O(E)
// 이 모든 간선이 최소 한번씩은 PQ에 삽입 -> O(logE)
// E개의 간선이 PQ에서 heapify를 한다 -> O(ElogE)
// ** 1. pq를 쓴다 2. 그래프의 구성은 인접 리스트다
void dijkstra(int start) {
	// priority queue
	priority_queue<Edge>pq;
	// 시작 노드를 삽입 
	pq.push({ start, 0 });
	// dist
	int dist[100] = { 0, };
	int MAX = 21e8;
	for (int i = 0; i < N; i++)
		dist[i] = MAX;
	dist[start] = 0; 
	// visited
	//int visited[100] = { 0, }; 
	// 구현 단계
	// 더이상 갈 후보지가 없을떄 까지 반복 
	while (!pq.empty()) {
		// 후보지 중 가장 가중치가 낮은 간선을 뽑아옵니다. 
		// priority queue -> cost를 기준으로 MINHEAP
		Edge now = pq.top();
		pq.pop(); 
		// 이미 확정된 노드라면 이 노드에 대해서는 아무것도 안해도 된다!
		//if (visited[now.to] == 1)
			//continue; 
		// now까지의 최단거리 확정된다! 
		//visited[now.to] = 1; 
		// 이미 now로 나왔던 노드 -> 첫번쨰 나왔을때 거리가 확정
		// 이후에 나온 now와 같은번 노드 = 절대 dist에 기록된 값보다 작을일 없다. 
		// 만약 now랑 같은 번호가 다시 나왔는데, 이게 dist에 기록된것보다 크면 -> 
		// 이 전에 이미 확정된 노드이니 -> 여기서부터 더 볼 필요 없다! 
		if (dist[now.to] < now.cost)
			continue;
		// now로부터 갈수 있는 간선들을 확인
		for (int i = 0; i < al[now.to].size(); i++) {
			Edge next = al[now.to][i];
			// ncost = next번까지의 최종 비용
			int ncost = dist[now.to] + next.cost; 
			// 만약 지금 최종 비용이 이미 기록되어있는 후보 경로의 비용보다 크거나 같으면
			if (dist[next.to] <= ncost)
				continue; // 쓸모없는 경로 
			// next까지 가기 위한 새로운 최단 거리  찾음!~
			dist[next.to] = ncost; 
			// 새로운 후보지로 등록 
			pq.push({ next.to, ncost });
		}
	}
	for (int i = 0; i < N; i++) {
		cout << i << " 까지의 최단 거리 : " << dist[i] << '\n';
	}
}
int main() {
	cin >> N >> M;
	// 간선 정보 입력
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost; 
		al[from].push_back({ to, cost });
		al[to].push_back({ from, cost });
	}
	dijkstra(0); 
}
```

# 오프라인
**DFS로 모든 경로 탐색**
```cpp
#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct Edge {
	int node; 
	int cost; 
};
int N, T; 
vector<Edge> adj[8]; 
void input() {
	cin >> N >> T; 
	for (int i = 0; i < T; i++)
	{
		int a, b, cost; 
		cin >> a >> b >> cost; 
		adj[a].push_back({ b,cost });
	}
}
int cnt = 0; 
int visited[8]; // 경로상에 중복 등장하지 않도록 막기
void dfs(int now,int accSum,string path)
{
	if (now == 6) { // 1 ~~~~>6
		cnt++;
		cout << "경로 발견!" << accSum << " " << path << "\n";
		return; 
	}
	for (Edge next : adj[now])
	{
		if (visited[next.node] == 1) continue; 
		visited[next.node] = 1; // 이후 경로에서 등장 x 
		dfs(next.node, accSum + next.cost, path + to_string(next.node) + "->"); // 1 ~~~~>
		visited[next.node] = 0;
	}
}
int main() {
	input(); 
	visited[1] = 1; // 1번지점은 이후에 다시 등장 안한다.
	dfs(1,0,"1->");
	cout << cnt; 
	return 0;
}
```

**수도 다익스트라**
```cpp
#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct Edge {
	int node; 
	int cost; 
};
struct Node {
	int node; // start ~~~~ > node
	int accCost; // start~~~>node 까지의 누적비용 
};
struct cmp
{
	bool operator() (Node& left, Node& right)
	{
		return left.accCost > right.accCost; 
	}
};
int N, T; 
vector<Edge> adj[8]; 
void input() {
	cin >> N >> T; 
	for (int i = 0; i < T; i++)
	{
		int a, b, cost; 
		cin >> a >> b >> cost; 
		adj[a].push_back({ b,cost });
	}
}
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input(); 
	// 가짜 dijkstra 
	priority_queue<Node, vector<Node>, cmp> pq; 
	int processed[8] = { 0 }; 
	int start = 1; 
	pq.push({ start, 0}); // start, start~~>start비용
	int dist[8] = { 0 }; 
	while (!pq.empty())
	{
		Node now = pq.top(); pq.pop(); 
		if (processed[now.node] == 1)continue; 
		processed[now.node] = 1; 
		dist[now.node] = now.accCost;
		// proccess 
		for (Edge& next : adj[now.node])
		{
			int newCost = now.accCost + next.cost; // start~~~~>now + 간선비용
			pq.push({ next.node, newCost }); 
		}
	}
	for (int node = 1; node <= 7; node++)
	{
		cout << start << "~~~~~~>" << node << "의 최소비용 : " << dist[node] << endl; 
	}
	return 0;
}

```

**다익스트라**
```cpp
#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct Edge {
	int node; 
	int cost; 
};
struct Node {
	int node; // start ~~~~ > node
	int accCost; // start~~~>node 까지의 누적비용 
};
struct cmp
{
	bool operator() (Node& left, Node& right)
	{
		return left.accCost > right.accCost; 
	}
};
int N, T; 
vector<Edge> adj[8]; 
void input() {
	cin >> N >> T; 
	for (int i = 0; i < T; i++)
	{
		int a, b, cost; 
		cin >> a >> b >> cost; 
		adj[a].push_back({ b,cost });
	}
}
const int INF = 1e9; // 10억 
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input(); 
	priority_queue<Node, vector<Node>, cmp> pq; 
	int dist[8];  // dist[A] : PQ에 있는 A의 제일 작은 누적비용 
	for (int i = 1; i <= 7; i++) dist[i] = INF; 
	int processed[8] = { 0 };
	int start = 1; 
	pq.push({ start, 0}); // start, start~~>start비용
	dist[start] = 0; 
	while (!pq.empty())
	{
		Node now = pq.top(); pq.pop(); 
		if (processed[now.node] == 1)continue; 
		processed[now.node] = 1; 
		// proccess 
		for (Edge& next : adj[now.node])
		{
			int newCost = now.accCost + next.cost; // start~~~~>now + 간선비용
			if (newCost < dist[next.node])
			{
				dist[next.node] = newCost; 
				pq.push({ next.node, dist[next.node]});
			}
		}
	}
	for (int node = 1; node <= 7; node++)
	{
		cout << start << "~~~~~~>" << node << "의 최소비용 : " << dist[node] << endl; 
	}
	
	return 0;
}

```

**최소비용 구하기**
```cpp
#include <iostream>
#include <queue>
#include <string>
using namespace std;
struct Edge {
	int node; 
	int cost; 
};
struct Node {
	int node; // start ~~~~ > node
	int accCost; // start~~~>node 까지의 누적비용 
};
struct cmp
{
	bool operator() (Node& left, Node& right)
	{
		return left.accCost > right.accCost; 
	}
};
int N, T; 
vector<Edge> adj[8]; 
void input() {
	cin >> N >> T; 
	for (int i = 0; i < T; i++)
	{
		int a, b, cost; 
		cin >> a >> b >> cost; 
		adj[a].push_back({ b,cost });
	}
}
const int INF = 1e9; // 10억 
int main() {
	freopen_s(new FILE*, "input.txt", "r", stdin);
	input(); 
	priority_queue<Node, vector<Node>, cmp> pq; 
	int dist[8];  // dist[A] : PQ에 있는 A의 제일 작은 누적비용 
	for (int i = 1; i <= 7; i++) dist[i] = INF; 
	int start = 1; 
	pq.push({ start, 0}); // start, start~~>start비용
	dist[start] = 0; 
	while (!pq.empty())
	{
		Node now = pq.top(); pq.pop(); 
		if (now.accCost > dist[now.node])continue;
		// proccess 
		for (Edge& next : adj[now.node])
		{
			int newCost = now.accCost + next.cost; // start~~~~>now + 간선비용
			if (newCost < dist[next.node])
			{
				dist[next.node] = newCost; 
				pq.push({ next.node, dist[next.node]});
			}
		}
	}
	for (int node = 1; node <= 7; node++)
	{
		cout << start << "~~~~~~>" << node << "의 최소비용 : " << dist[node] << endl; 
	}
	
	return 0;
}

```