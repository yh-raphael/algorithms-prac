#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int M, N, K;
int map[100][100] = { 0, };     // 0: blank, 1: rectangle area.
//int map_copied[100][100] = { 0, }; // 0: blank, 1: rectangle area.

int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};
int do_bfs (int sr, int sc)
{
    queue <pair <int, int> > Q;
    Q.push (make_pair (sr, sc));
    map[sr][sc] = 2;
    int cnt = 1;

    while (Q.empty () == false)
    {
        int r = Q.front ().first;
        int c = Q.front ().second;
        Q.pop ();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            if (nr < 0 || nr > N-1 || nc < 0 || nc > M-1) continue;
            if (map[nr][nc] != 0) continue;

            Q.push (make_pair (nr, nc));
            map[nr][nc] = 2;
            cnt ++;
        }
    }

    return cnt;
}

int main (void)
{
    cin >> M >> N >> K;                 // N: row, M: col.
    for (int t = 0; t < K; t++) {
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;
        // mark rectangle area.
        for (int i = r1; i < r2; i++) {
            for (int j = c1; j < c2; j++) {
                map[i][j] = 1;
            }
        }
    }

    //memcpy (map_copied, map, sizeof (map));
    // cout << endl;
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << map_copied[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    // do BFS for each coordinate.

    priority_queue <int, vector <int>, greater <int> > PQ;
    // priority_queue <int> PQ;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (map[i][j] == 0) {
                int area = do_bfs (i, j);   //cout << "area: " << area << endl;
                PQ.push (area);
            }
        }
    }

    int iter = PQ.size ();
    cout << iter << '\n';
    for (int i = 0; i < iter; i++) {
        cout << PQ.top () << ' ';
        PQ.pop ();
    }
    cout << '\n';

    // cout << endl;
    // for (int i = 0; i < N; i++) {
    //     for (int j = 0; j < M; j++) {
    //         cout << map[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    return 0;
}