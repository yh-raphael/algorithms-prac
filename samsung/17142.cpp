#include <iostream>
#include <vector>       // vector <pair <int, int> > V, V.push_back (make_pair (i, j)).
#include <utility>      // make_pair (nr, nc).
#include <cstring>      // memset (check, -1, sizeof (check)).
#include <queue>        // queue <pair <int, int> > Q, Q.push (V[i]), Q.front ().first, Q.front ().second, Q.pop ().
#include <climits>      // int result = INT_MAX.
#include <algorithm>    // result = min (result, elap_time), fill (&check[0][0], &check[49][50], -1).
using namespace std;

int N, M;
int map[50][50];
int empty_cnt = 0;
int check[50][50];

int dr[4] = {0, 1, 0, -1};  // east, south, west, north.
int dc[4] = {1, 0, -1, 0};

vector <pair <int, int> > V;
bool V_position[10] = { false, };

int result = INT_MAX;

void bfs (queue <pair <int, int> > Q)
{
    int spread_cnt = 0;
    int elap_time = 0;
    while (!Q.empty ())
    {
        // [Pop]
        int r = Q.front ().first;
        int c = Q.front ().second;
        Q.pop ();
        // [Push and Check]: (r, c) => (nr, nc)
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            // out of boundary.
            if (nr < 0 || nr > N-1 || nc < 0 || nc > N-1) continue;
            // wall.
            if (map[nr][nc] == 1) continue;
            // is already visited?
            if (check[nr][nc] != -1) continue;

            // empty part.
            if (map[nr][nc] == 0) {
                Q.push (make_pair (nr, nc));
                check[nr][nc] = check[r][c] + 1;
                // record elapsed time.
                spread_cnt ++;
                elap_time = check[nr][nc];
            }
            // non-active virus part.
            else if (map[nr][nc] == 2) {
                Q.push (make_pair (nr, nc));
                check[nr][nc] = check[r][c] + 1;
            }
        }
    }
    if (spread_cnt == empty_cnt) {
        result = min (result, elap_time);
    }
}

void select_virus_position (int idx, int cnt)
{
    // Escape condition.
    if (cnt == M) {
        // memset (check, -2, sizeof(check));
        fill (&check[0][0], &check[49][50], -1);
        queue <pair <int, int> > Q;
        // [Push and Check]
        for (unsigned int i = 0; i < V.size (); i++) {
            // combination.
            if (V_position[i] == true) {
                Q.push (V[i]);
                check[V[i].first][V[i].second] = 0;
            }
        }
        bfs (Q);
        return;
    }

    // back_tracking: recursion.
    for (unsigned int i = idx; i < V.size (); i++) {
        V_position[i] = true;
        select_virus_position (i + 1, cnt + 1);
        V_position[i] = false;
    }
}

int main (void)
{
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            // virus position candidate.
            if (map[i][j] == 2) {
                V.push_back (make_pair (i, j));
            }
            // empty position.
            if (map[i][j] == 0) {
                empty_cnt ++;
            }
        }
    }

    // Virus combination -> back_tracking!
    select_virus_position (0, 0);
    
    // print result.
    if (result == INT_MAX)
        cout << "-1" << '\n';
    else
        cout << result << '\n';
    return 0;
}