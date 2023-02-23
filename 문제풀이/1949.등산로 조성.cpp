#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
using namespace std;
// SWEA 1949. 등산로 조성
// Flood Fill로 시도하려고 했으나, DFS가 더 나은 것 같다.
// 플러드 필 백업을 위한 파일
/*
int T;
int map[8][8];
int N, K;

struct topPos
{
    int y, x;
};

queue<topPos> tops;

struct Node
{
    int y, x, len, deep;
    bool isDigged;
};

queue<Node> q;
unordered_map<string, int> um;

void BFS(topPos top)
{
    int visited[8][8] = {0};
    Node top = {top.y, top.x, 1, 0, false};
    q.push({top.y, top.x, 1, 0, false});

    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};

    bool isDigged = false;

    while (!q.empty())
    {
        Node now = q.front();
        q.pop();
        for (int d = 0; d < 4; d++)
        {
            int ny = now.y + dy[d];
            int nx = now.x + dx[d];
            if (ny >= 0 && nx >= 0 && ny < N && nx < N && now.visited[ny][nx] == 0)
            {
                if (map[now.y][now.x] + now.deep > map[ny][nx])
                {
                    q.push({ny, nx, now.len + 1, 0, now.isDigged});
                }
                else if (now.isDigged == false)
                {
                    for (int dig = 1; dig <= K; dig++)
                    {
                        q.push({ny, nx, now.len + 1, -dig, true});
                    }
                }
            }
        }
        lenList.push_back(now.len);
    }
}

int main()
{
    // reset
    int highest = -21e8;

    cin >> T;
    for (int tc = 1; tc <= T; tc++)
    {
        // input
        cin >> N >> K;
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                cin >> map[i][j];
                if (highest < map[i][j])
                {
                    highest = map[i][j];
                }
            }
        }
        // solve

        // 등산로 꼭대기의 포지션들 벡터에 넣기
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (map[i][j] == highest)
                {
                    tops.push({i, j});
                }
            }
        }

        // 플러드필 수행
        while (!tops.empty())
        {
            topPos nowTop = tops.front();
            tops.pop();
            BFS(nowTop);
        }
        int de = -1;
        // output
    }
}
*/