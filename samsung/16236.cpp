#include <iostream>
#include <vector>
#include <queue>
#include <utility>      // make_pair ().
#include <algorithm>    // sort ().
#include <cstring>
using namespace std;

int N;
int map[21][21];
int dr[4] = {-1, 0, 0, 1};
int dc[4] = {0, -1, 1, 0};
int check[21][21] = { 0, };    // for saving distance.

int cur_r, cur_c;
int shark_size = 2;
int eat_count = 0;

void print_debug (void)
{
    cout << endl;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
    return;
}

bool is_inside (int r, int c)
{
    if (1 <= r && r <= N && 1 <= c && c <= N)
        return true;
    else
        return false;
}

pair <int, int> search_prey_bfs (void)
{
    int min_dist = 21 * 21;
    int min_r = 55;
    int min_c = 55;

    int r = cur_r;
    int c = cur_c;
    int cur_depth = 0;

    queue < pair < pair <int, int>, int > > Q;
    memset (check, 0, 21 * 21 * sizeof(int));

    // bfs start!
    Q.push (make_pair (make_pair (r, c), cur_depth));
    check[r][c] = -1;
    while (Q.empty () == false)
    {
        r = Q.front ().first.first;
        c = Q.front ().first.second;
        cur_depth = Q.front ().second;
        Q.pop ();

        // prey found!
        if (0 < map[r][c] && map[r][c] < shark_size) {
            // 거리가 더 작으면 업데이트.
            if (cur_depth < min_dist) {
                min_r = r;
                min_c = c;
                min_dist = cur_depth;
            }
            // 거리가 같으면 위치 비교.
            else if (min_dist == cur_depth) {
                // 더 위에 있으면,
                if (r < min_r) {
                    min_r = r;
                    min_c = c;
                }
                // 높이 같으면 가장 왼쪽.
                else if (r == min_r) {
                    if (c < min_c) {
                        min_r = r;
                        min_c = c;
                    }
                }
            }
        }
        // unless, search more...
        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            // not available!
            if (is_inside (nr, nc) == false)
                continue;
            if (check[nr][nc] != 0)
                continue;
            if (map[nr][nc] > shark_size)
                continue;
            // available!
            Q.push (make_pair (make_pair (nr, nc), cur_depth + 1));
            check[nr][nc] = cur_depth + 1;
        }
    }
    // no candidate.
    return make_pair (min_r, min_c);
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL); cout.tie (NULL);

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
        pair <int, int> new_position;
        // search the nearest prey.
        new_position = search_prey_bfs ();  // Dependency: cur_r, cur_c, shark_size.

        // no prey? -> break!
        if (new_position.first == 55 && new_position.second == 55) {
            break;
        }
        
        // (1) eat prey.
        eat_count ++;
        // (2) udpate shark_size.
        if (shark_size == eat_count) {
            shark_size ++;
            eat_count = 0;
        }
        // calculate time(distance).
        result += check[new_position.first][new_position.second];
        // result += abs (new_position.first - cur_r) + abs (new_position.second - cur_c);
        // (3) move to that position.
        map[new_position.first][new_position.second] = 0;
        // map[cur_r][cur_c] = 0;
        cur_r = new_position.first;
        cur_c = new_position.second;
        

        // print_debug (); cout << "result: " << result << ", shark_size: " << shark_size << endl;
    }
    // print_debug (); cout << "result: " << result << ", shark_size: " << shark_size << endl;

    cout << result << '\n';
    return 0;
}