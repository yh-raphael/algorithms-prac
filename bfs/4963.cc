// Written by Raphael on 2022-01-02-Mon.
// Num of Islands: Graph, BFS, DFS.

#include <iostream>
#include <queue>        // Q.empty(), Q.front(), Q.pop(), Q.push();
#include <cstring>      // memset (check, false, sizeof(check) / sizeof(bool));
#include <utility>      // pair, make_pair (nx, ny)

using namespace std;

int W, H;

int island [51][51];
bool check [51][51];
int cnt;

queue <pair <int, int> > Q;
int dx[8] = {1, 0, -1, -1, -1, 0, 1, 1};
int dy[8] = {1, 1, 1, 0, -1, -1, -1, 0};

void bfs (int x, int y)
{
    Q.push (make_pair (x, y));
    check [x][y] = true;

    // Iteration.
    while (!Q.empty())
    {
        int x = Q.front ().first;
        int y = Q.front ().second;
        Q.pop ();

        // 8 directions including diagonals.
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 || nx > H || ny < 1 || ny > W)
                continue;

            if (!check[nx][ny] && island[nx][ny] == 1)
            {
                Q.push (make_pair (nx, ny));
                check [nx][ny] = true;
            }
        }
    }
}

int main (void)
{
    ios_base::sync_with_stdio (0);
    cin.tie (NULL); cout.tie (NULL);

    while (1)
    {
        cin >> W >> H;
        if (W == 0 && H == 0)
            break;

        // Island input.
        for (int i = 1; i <= H; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                cin >> island[i][j];
            }
        }

        memset (check, false, sizeof(check) / sizeof (bool));
        cnt = 0;

        // BFS.
        for (int i = 1; i <= H; i++)
        {
            for (int j = 1; j <= W; j++)
            {
                // Only star when it is a land block.
                if (!check[i][j] && island[i][j] == 1) {
                    // cout << "here " << i << j << '\n';
                    bfs (i, j);
                    cnt ++;
                }
            }
        }
        
        cout << cnt << '\n';
    }
    
    return 0;
}