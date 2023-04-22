#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <cstring>
using namespace std;

int T, M, N, K;
int map[51][51] = { 0, };           // index: 0~50, 0~50.
bool check[51][51] = { false, };    // index: 0~50, 0~50.
vector <int> result;

int dr[4] = {0, 1, 0, -1};      // east, south, west, north.
int dc[4] = {1, 0, -1, 0};      // east, south, west, north.

void do_bfs (int sr, int sc)
{
    queue <pair <int, int> > Q;
    Q.push (make_pair (sr, sc));
    check[sr][sc] = true;

    while (Q.empty () == false)
    {
        int r = Q.front ().first;
        int c = Q.front ().second;
        Q.pop ();

        // for each direction.
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr < 0 || nr > M-1 || nc < 0 || nc > N-1) continue;     // out of boundary.
            if (map[nr][nc] == false) continue;     // no lettuce.
            if (check[nr][nc] == true) continue;    // is visited already.

            Q.push (make_pair (nr, nc));
            check[nr][nc] = true;
        }
    }
    
    return;
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL); cout.tie (NULL);
    cin >> T;
    // for each test case.
    for (int iter = 0; iter < T; iter++) {
        cin >> M >> N >> K;

        // set the map.
        memset (map, 0, sizeof (map));
        memset (check, 0, sizeof (check));
        for (int j = 0; j < K; j++) {
            int r, c; cin >> r >> c;
            map[r][c] = 1;
        }

        // solve.
        int cnt = 0;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] == 1 && check[i][j] == false) {

                    // cout << endl << endl << i << "," << j << endl;
                    // for (int ii = 0; ii < M; ii ++) {
                    //     for (int jj = 0; jj < N; jj ++) {
                    //         cout << check[ii][jj] << ' ';
                    //     }
                    //     cout << endl;
                    // }

                    do_bfs (i, j);  // do the bfs!

                    // cout << endl;
                    // for (int ii = 0; ii < M; ii ++) {
                    //     for (int jj = 0; jj < N; jj ++) {
                    //         cout << check[ii][jj] << ' ';
                    //     }
                    //     cout << endl;
                    // }

                    cnt ++;
                }
            }
        }
        // store the result.
        result.push_back (cnt);
    }

    // print results.
    for (int iter = 0; iter < T; iter ++) {
        cout << result[iter] << '\n';
    }
    return 0;
}