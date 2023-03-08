#include <iostream>
#include <cstring>      // memset (map, 0, sizeof(map)), memcpy (tmp, MAP, sizeof (MAP))
#include <queue>
#include <utility>      // make_pair (i, j)
#include <algorithm>    // answer = max (answer, count);
using namespace std;

int N, M;
int MAP[8][8] = { 0, };
int tmp[8][8] = { 0, };         // in the bfs()
int answer = 0;

int dx[4] = {1, 0 , -1, 0};     // downward - N
int dy[4] = {0, 1 , 0, -1};     // rightward - M

void bfs ()
{
    int bfs_map[8][8];
    memcpy (bfs_map, tmp, sizeof(tmp));

    queue <pair <int, int> > q;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (bfs_map[i][j] == 2) {       // multiple bfs starting points.
                q.push (make_pair (i, j));
            }
        }
    }

    while (!q.empty ())
    {
        int x = q.front ().first;
        int y = q.front ().second;
        q.pop ();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // boundary check.
            if (nx < 0 || nx >= N || ny < 0 || ny >= M)// || bfs_map[nx][ny] == 1)
                continue;

            // virus update.
            if (bfs_map[nx][ny] == 0) {     // bfs_map 값이 2인 경우는 고려할 필요 x!
                bfs_map[nx][ny] = 2;
                q.push (make_pair (nx, ny));
            }
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (bfs_map[i][j] == 0)
                count ++;
        }
    }

    answer = max (answer, count);
    return;
}

void solve (int change_num)
{
    if (change_num == 3) {
        bfs ();
        return;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (tmp[i][j] == 0) {
                tmp[i][j] = 1;
                solve (change_num + 1);
                tmp[i][j] = 0;
            }
        }
    }
}

int main (void)
{
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> MAP[i][j];
        }
    }

    // Brute force back tracking: stage 1.
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (MAP[i][j] == 0) {
                memcpy (tmp, MAP, sizeof(MAP));     // for every new start.
                tmp[i][j] = 1;
                solve (1);
                tmp[i][j] = 0;
            }
        }
    }

    cout << answer << '\n';
    return 0;
}