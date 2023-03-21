#include <iostream>
#include <queue>
#include <vector>
#include <utility>      // make_pair (r, c).
#include <cmath>        // abs (map[r][c] - map[nr][nc]).
#include <algorithm>    // fill (check[0], check[0] + 51*51, false).
using namespace std;

int N, L, R;
int map[51][51] = { 0, };    // [0~50][0~50]
bool check[51][51] = { false, };
int dr[4] = {0, 1, 0, -1};
int dc[4] = {1, 0, -1, 0};

queue <pair <int, int> > Q;
vector <pair <int, int> > V;
int sum = 0;

// [DEBUG]
// void print_info ()
// {
//     cout << "--map--" << endl;
//     cout << N << ' ' << L << ' ' << R << endl;
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             cout << map[i][j] << ' ';
//         }
//         cout << endl;
//     }
//     cout << "--check--" << endl;
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             cout << check[i][j] << ' ';
//         }
//         cout << endl;
//     }
//     return;
// }

// void clear_check ()
// {
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             check[i][j] = false;
//         }
//     }
//     return;
// }

void bfs (int start_r, int start_c)
{   
    Q.push (make_pair (start_r, start_c));      //cout << start_r << ", " << start_c << endl;
    check[start_r][start_c] = true;
    V.push_back (make_pair (start_r, start_c));
    sum += map[start_r][start_c];
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
            // border check.
            if (check[nr][nc] == false && 0 <= nr && nr <= N-1 && 0 <= nc && nc <= N-1 &&
                    L <= abs (map[r][c] - map[nr][nc]) && abs (map[r][c] - map[nr][nc]) <= R) {
                Q.push (make_pair (nr, nc));    //cout << nr << ", " << nc << endl;
                check[nr][nc] = true;
                V.push_back (make_pair (nr, nc));
                sum += map[nr][nc];
            }
        }
    }
    // cout << "sum: " << sum << endl;
    return;
}

int main (void)
{
    cin >> N >> L >> R;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    int count = 0;
    bool flag = true;
    while (flag == true)
    {
        fill (check[0], check[0] + 51*51, false);
        flag = false;
        // for each map element.
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                V.clear ();
                sum = 0;
                // visited condition check.
                if (check[i][j] == false) {
                    // start bfs!
                    bfs (i, j);
                }
                // merged land check.
                if (V.size () > 1) {    //cout << V.size () << "==============" <<endl;
                    flag = true;
                    int new_num = sum / V.size ();
                    for (unsigned int i = 0; i < V.size (); i++)
                    {
                        map[V[i].first][V[i].second] = new_num;
                    }
                }
            }
        }
        // 1 Day elpased.
        if (flag == true) count ++;
    }
    
    cout << count << '\n';
    return 0;
}