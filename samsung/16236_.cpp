#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

int N;
int map[21][21];
int dist[21][21];   // check 대신 활용!! (bool 대신 int 정보로!!)

int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};

int cur_r, cur_c;
int shark_size = 2;
int eat_count = 0;

int min_dist, min_r, min_c;

void init_distance (void)
{
    min_dist = INT_MAX;
    min_r = INT_MAX;
    min_c = INT_MAX;

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            dist[i][j] = -1;
        }
    }
}

void bfs (int r, int c)
{
    queue <pair <int, int> > Q;
    dist[r][c] = 0;
    Q.push (make_pair (r, c));

    while (Q.empty () == false)
    {
        pair <int, int> cur = Q.front ();
        Q.pop ();
        r = cur.first;
        c = cur.second;
        // 4방향 탐색.
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];

            // out of boundary.
            if (nr < 1 || nr > N || nc < 1 || nc > N) continue;
            // already visited or bigger fish.
            if (dist[nr][nc] != -1 || map[nr][nc] > shark_size) continue;

            dist[nr][nc] = dist[r][c] + 1;
            Q.push (make_pair (nr, nc));

            // 먹을 수 있는 물고기.
            if (0 < map[nr][nc] && map[nr][nc] < shark_size)
            {
                // 거리가 더 짧으면.
                if (min_dist > dist[nr][nc]) {
                    min_r = nr;
                    min_c = nc;
                    min_dist = dist[nr][nc];
                }
                // 거리 같으면, 우선순위 체크.
                else if (min_dist == dist[nr][nc]) {
                    if (min_r == nr) {
                        if (min_c > nc) {
                            min_r = nr;
                            min_c = nc;
                        }
                    }
                    else if (min_r > nr) {
                        min_r = nr;
                        min_c = nc;
                    }
                }
            }
        }
    }
}

int main (void)
{
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 9) {
                cur_r = i;
                cur_c = j;
                map[i][j] = 0;
            }
        }
    }

    int result = 0;
    while (1)
    {
        init_distance ();

        bfs (cur_r, cur_c);

        // can eat something.
        if (min_r != INT_MAX && min_c != INT_MAX) {
            result += dist[min_r][min_c];
            eat_count ++;
            if (eat_count == shark_size) {
                shark_size ++;
                eat_count = 0;
            }
            // map update, shark position update.
            map[min_r][min_c] = 0;
            cur_r = min_r;
            cur_c = min_c;
        }
        else {
            break;
        }
    }

    cout << result << '\n';
    return 0;
}