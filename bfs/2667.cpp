// Imprint this logic to the head.. rudimentary and fundamental
#include <iostream>
#include <queue>        // queue <pair <int, int> > Q, Q.push (), int x = Q.front().first, int y = Q.front().second, Q.pop ();
#include <algorithm>    // sort (result.begin (), result. end ()), sort (result.begin (), result. end (), greater <int> ());
#include <vector>       // vecotr <int> result, result.push_back (danji_size), result.size ();
#include <utility>      // make_pair (x, y), make_pair (nx, ny)
using namespace std;

int N;
char map[26][26];
bool check[26][26] = { 0, };

int bfs (int x, int y)
{
    queue <pair <int, int> > Q;
    // diagonal X!!! - differential :)
    int dx[8] = {0, -1, 0, 1};
    int dy[8] = {1, 0, -1, 0};
    int cnt = 0;

    // initial push!
    Q.push (make_pair (x, y));
    check[x][y] = true;
    cnt ++;

    while (Q.empty () == false)
    {
        // initial pop!
        int x = Q.front ().first;
        int y = Q.front ().second;
        Q.pop ();

        for (int i = 0; i < 8; i++)
        {
            for (int i = 0; i < 8; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];

                // boundary check!
                if (nx < 1 || nx > N || ny < 1 || ny > N)
                    continue;

                // subsequent push!!!
                if (map[nx][ny] == '1' && check[nx][ny] == false) {
                    Q.push (make_pair (nx, ny));
                    check[nx][ny] = true;
                    cnt ++;
                }
            }
        }
    }

    return cnt;
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL); cout.tie (NULL);

    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> map[i][j];
        }
    }

    vector <int> result;
    int count = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (map[i][j] == '1' && check[i][j] == false) {
                int danji_size = bfs (i, j);
                count++;
                result.push_back (danji_size);
            }
        }
    }
    
    sort (result.begin (), result.end ());
    cout << count << '\n';
    for (unsigned int i = 0; i < result.size (); i++)
    {
        cout << result[i] << '\n';
    }
    return 0;
}