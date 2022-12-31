// Written by Raphael 2023-01-01-Sun.
#include <iostream>
#include <cstring>      // memset (visitied, false, sizeof(visited) / sizeof(bool));

using namespace std;

int N;
char picture[101][101];
bool visited[101][101];

// difference array.
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs (int x, int y)
{
    visited[x][y] = true;

    int nx, ny;
    
    // Recursion.
    for (int i = 0; i < 4; i++)
    {
        nx = x + dx[i];
        ny = y + dy[i];

        if (nx < 1 || nx > N || ny < 1 || ny > N)
            continue;
        
        if (!visited[nx][ny] && picture[x][y] == picture[nx][ny])
            dfs (nx, ny);
    }
}

int main (void)
{
    ios_base :: sync_with_stdio (0);
    cin . tie (0); cout.tie (0);

    int count = 0;
    
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            cin >> picture[i][j];
    }

    // Normal.
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (!visited[i][j])
            {
                dfs (i, j);
                count ++;
            }
        }
    }
    cout << count << '\n';

    // Red-Green Weakness -> confusion.
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (picture[i][j] == 'G')
                picture[i][j] = 'R';
        }
    }

    // Reset visited board and do the dfs.
    count = 0;
    memset (visited, false, sizeof(visited) / sizeof(bool));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (!visited[i][j])
            {
                dfs (i, j);
                count ++;
            }
        }
    }
    cout << count << '\n';

    return 0;
}