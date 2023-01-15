// BFS, Adjacent Matrix implementation: 2023-01-16-Mon
#include <iostream>
#include <queue>
using namespace std;

int map[101][101] = { 0, };
bool isVisited[101] = { 0, };
int depth[101] = { 0, };

queue <int> q;

void bfs (int v)
{
    q.push (v);
    isVisited[v] = true;

    while (!q.empty ())
    {
        int cur = q.front ();
        q.pop ();

        for (int i = 0; i < 101; i++)
        {
            if (map[cur][i] == 1 && isVisited[i] == 0)
            {
                q.push (i);
                isVisited[i] = true;
                depth[i] = depth[cur] + 1;
            }
        }
    }
}

int main (void)
{
    int N, X, Y, M;
    cin >> N;
    cin >> X >> Y;
    cin >> M;

    for (int i = 1; i <= M; i++)
    {
        int a, b; cin >> a >> b;
        map[a][b] = 1;
        map[b][a] = 1;
    }

    bfs (X);

    if (depth[Y] == 0)
        cout << -1 << '\n';
    else
        cout << depth[Y] << '\n';

    return 0;
}