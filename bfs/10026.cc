// Written by Raphael on 2023-01-16-Mon.
#include <iostream>
#include <queue>        // queue <pair <int, int> > Q, Q.front(), Q.pop(), Q.push()
#include <utility>      // pair, make_pair (cur_x + dx[i], cur_y + dy[i])
#include <cstring>      // memset (isVisited, false, sizeof (isVisited))

using namespace std;

int N;
char photo[101][101];
bool isVisited[101][101] = { false, };

// Difference Array.
int dx[4] = { 0, 1, 0, -1};
int dy[4] = { -1, 0, 1, 0};

void bfs (int x, int y)
{
    queue <pair <int, int> > Q;
    Q.push (make_pair (x, y));
    isVisited[x][y] = true;

    while (!Q.empty ())
    {
        int cur_x = Q.front ().first;
        int cur_y = Q.front ().second;
        Q.pop ();

        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                if (cur_x + dx[i] < 1 && cur_x + dx[i] > N && cur_y + dy[i] < 1 && cur_y + dy[i] > N)
                    continue;

                if (photo[cur_x][cur_y] == photo[cur_x + dx[i]][cur_y + dy[i]] && isVisited[cur_x + dx[i]][cur_y + dy[i]] == false)
                {
                    Q.push (make_pair (cur_x + dx[i], cur_y + dy[i]));
                    isVisited[cur_x + dx[i]][cur_y + dy[i]] = true;
                    // cout << cur_x + dx[i] << ' ' << cur_y + dy[i] << '\n';
                }
            }
        }
    }
}

int main (void)
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> photo [i][j];
        }
    }

    // Normal.
    int result = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (isVisited[i][j] == false) {
                bfs (i, j);
                result ++;
            }
        }
    }
    cout << result << ' ';

    // Wipe out the memory layout and Change the map.
    memset (isVisited, false, sizeof (isVisited));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (photo[i][j] == 'G') {
                photo[i][j] = 'R';
            }
        }
    }

    // Red-Green color weakness.
    result = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (isVisited[i][j] == false) {
                bfs (i, j);
                result ++;
            }
        }
    }
    cout << result << '\n';
    
    return 0;
}