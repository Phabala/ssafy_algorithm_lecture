#include <iostream>
#include <vector>

using namespace std;

int nodeCnt, edgeCnt;
int adj[6][6] = {
    0,
}; // adj[from][to] 갈 수 있는가?

void dfs인접행렬(int now)
{
    // 지금 now라는 점에 도착했다!

    // 2. 기저조건(기저조건은 option으로 필수가 아님)

    for (int to = 1; to <= nodeCnt; to++)
    {
        // 재귀에서 가지치기와 비슷 (가능한지 판별)
        if (adj[now][to] == 0)
            continue; // now -> to 로 갈 수 없으면 무시

        cout << now << "에서 " << to << "로 갑니다!" << endl;
        // 1. 재귀 기본 구조
        dfs인접행렬(to);
    }
}

vector<int> v[6]; // v[from] : from에서 갈 수 있는 to'들'을 저장한 vector
vector<int> path; // 지금 들리고 있는 node 들의 경로
int used[6];      // used, visited -> 갔던 점인지 판별

void dfs인접리스트(int now)
{
    // 2. 기저조건
    if (now == 5)
    { // 끝점으로 5로 하고 싶은 경우
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
            return;
        }
    }

    for (int i = 0; i < v[now].size(); i++)
    {
        // now -> to 찾기
        int to = v[now][i];

        // 4. 가지치기(판별)
        if (used[to] == 1)
            continue; // 갔던 점이면 무시 (같은 곳 방문 방지)

        // 3. 기록 및 처리
        cout << now << "에서" << to << "로 갑니다!\n";
        used[to] = 1; // to에 왔었다고 기록
        path.push_back(to);

        // 1. 재귀 기본 구조
        dfs인접리스트(to);

        // 3. 복구
        path.pop_back(); // vector.pop_back() : vector의 맨 뒤 data를 메모리까지 '삭제'
        used[to] = 0;    // used를 다시 복구 : 실제 경로와 완벽하게 일치
        // used를 복구 안한다면 단순하게 모든 점들을 정확히 한번씩만 들려봐야 할 때
        // 다양한 경로는 필요 없고, 딱 한번만이라도 7까지만 가면 된다
    }
}

int main()
{
    /*
    5 4 <- node 개수, edge 개수
    1 2 <- edge 정보(from, to)
    1 3 <- edge 정보(from, to)
    1 4 <- edge 정보(from, to)
    2 5 <- edge 정보(from, to)
    */

    cin >> nodeCnt >> edgeCnt;
    // 1. 인접 행렬

    for (int i = 0; i < edgeCnt; i++)
    {
        int from, to;
        cin >> from >> to;
        adj[from][to] = 1;
    }
    int de = 1; // 얘는 뭘까

    // 특정 from에서 갈 수 있는 모든 to 찾기
    int node = 1; // 특정 from으로 둘 점
    for (int to = 1; to <= 5; to++)
    {
        if (adj[node][to] == 0)
            continue;
        // 갈 수 있는 점이다
        cout << to << " ";
    }

    // -----------------

    // int nodeCnt, edgeCnt;
    // cin >> nodeCnt >> edgeCnt;
    // // 2. 인접 리스트
    // vector<int> v[6]; // v[from] : from에서 갈 수 있는 to'들'을 저장한 vector
    // // vector<저장할 data형태> v;

    // for (int i = 0; i < edgeCnt; i++) {
    //     int from, to;
    //     cin >> from >> to;
    //     v[from].push_back(to);
    //     // vector.push_back(value) : vector의 맨 뒤에 공간을 추가해서 value라는 값을 저장
    // }
    // int de = 1;
    // // 특정 from에서 갈 수 있는 모든 to 찾기
    // int node = 1;
    // for (int i = 0; i < v[node].size(); i++) {
    //     // vector.size() : vector가 갖고 있는 데이터 개수
    //     int to = v[node][i];
    //     cout << to;
    // }

    // dfs인접행렬(1);
    // dfs인접리스트(1);
}

/* // 강사님 코드
#include <iostream>

#include <vector>
using namespace std;

// 5 4 <- node개수, edge개수
// 1 2 <- edge정보(from to)
// 1 3 <- edge정보(from to)
// 1 4 <- edge정보(from to)
// 2 5 <- edge정보(from to)


int nodeCnt, edgeCnt;
int adj[6][6] = { 0, }; // adj[from][to] = 갈 수 있는가?

void dfs인접행렬(int now) {
    // 지금 now라는 점에 도착했다!

// 2. 기저조건(option)
for (int to = 1; to <= nodeCnt; to++)
{
    // 재귀에서 다룰 때, ?기능적으로 비슷한 부분?
    // 가지치기(가능한지 판별)
    if (adj[now][to] == 0) continue; // now->to로 갈 수 없으면 무시

    cout << now << "에서" << to << "로 갑니다!\n";
    // 1. 재귀 기본 구조
    dfs인접행렬(to);
}
}

vector<int> v[8]; // v[from] : from에서 갈 수 있는 to'들'을 저장한 vector
// 갔던 점인지 판별
int used[8]; // used, visited
// used[node번호] = 해당 node를 들렸었는가?

vector<int> path; // 지금 들리고 있는 node들의 경로

void dfs인접리스트(int now) {
    // 2. 기저조건(option)
    if (now == 7) {
        for (int i = 0; i < path.size(); i++)
            cout << path[i] << " ";
        cout << "\n";
        return;
    }

for (int i = 0; i < v[now].size() ; i++) {
    // now->to찾기
    int to = v[now][i];
    // 4. 가지치기(판별)
    if (used[to] == 1) continue; // 갔던 점이면 무시

    // 3. 기록 및 처리
    cout << now << "에서" << to << "로 갑니다!\n";
    used[to] = 1; // 내가 to라는 점으로 간다라고 기록
    path.push_back(to);

    // 1. 재귀 기본 구조
    dfs인접리스트(to);

    // 3. 복구
    path.pop_back(); // vector.pop_back() : vector의 맨 뒤 data를 메모리까지 '삭제'
    used[to] = 0;
    // used를 다시 복구 : 실제 경로랑 완벽하게 일치
    // used를 다시 복구X: 단순하게 모든 점들을 정확히 1번씩만 들려볼 때
}
}

int main() {
    //cin >> nodeCnt >> edgeCnt;
    //// 1. 인접 행렬
    //for (int i = 0; i < edgeCnt; i++)
    //{
    //    int from, to;
    //    cin >> from >> to;
    //    adj[from][to] = 1;
    //}

// 특정 from에서 갈 수 있는 모든 to찾기
//int node = 1; // 특정 from으로 둘 점
//for (int to = 1; to <= 5; to++)
//{
//    if (adj[node][to] == 0) continue;
//    // 갈 수 있는 점이다.
//    cout << to <<" ";
//}
//dfs인접행렬(1);



int nodeCnt, edgeCnt;
cin >> nodeCnt >> edgeCnt;
// 2. 인접 리스트
// vector<저장할 data형태> v;

for (int i = 0; i < edgeCnt; i++)
{
    int from, to;
    cin >> from >> to;
    v[from].push_back(to);
    // vector.push_back(value) : vector의 맨 뒤에 공간을 추가해서 value라는 값을 저장
}

//// 특정 from에서 갈 수 있는 모든 to찾기
//int node = 1;
//for (int i = 0; i < v[node].size(); i++)
//    //vector.size() : vector가 갖고있는 data 개수
//{
//    int to = v[node][i];
//    cout << to << " ";
//}

path.push_back(1);
used[1] = 1; // 1번이라는 점을 간다라고 기록
dfs인접리스트(1); // 1번 점으로 감
}

*/