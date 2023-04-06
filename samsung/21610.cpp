#include <iostream>
#include <vector>
#include <utility>      // make_pair ().
#include <algorithm>    // fill (&mark[0][0], &mark[N][N+1], false).
using namespace std;

int N, M;
int A[51][51];  // index: 1~50 (position)
typedef struct _move_info {
    int d;
    int s;
} MoveInfo;
MoveInfo B[100];    // index: 0~100 (moving order)

int dr[9] = {0, 0, -1, -1, -1, 0, 1, 1, 1}; // index: 1~8 (direction of r)
int dc[9] = {0, -1, -1, 0, 1, 1, 1, 0, -1}; // index: 1~8 (direction of c)

int ddr[5] = {0, -1, -1, 1, 1}; // index: 1~4
int ddc[5] = {0, -1, 1, 1, -1}; // index: 1~4

bool mark[51][51] = { 0, };  // index: 1~50 (position)
vector <pair <int, int> > cld;

int result = 0;

void print_debug ()
{
    cout << endl;
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            cout << A[i][j] << ' ';
        }
        cout << endl;
    }
    // for (int i = 0; i < M; i++) {
    //     cout << B[i].d << ' ' << B[i].s << endl;
    // }
}

int main (void)
{
    cin >> N >> M;
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            cin >> A[i][j];
        }
    }
    for (int i = 0; i < M; i++) {
        cin >> B[i].d >> B[i].s;
    }
    //print_debug ();

    // 0. make cloud.
    cld.push_back (make_pair (N, 1));
    cld.push_back (make_pair (N, 2));
    cld.push_back (make_pair (N-1, 1));
    cld.push_back (make_pair (N-1, 2));
    // [DEBUG] - cld position
    // for (unsigned int i = 0; i < cld.size (); i++) {
    //     cout << "(" << cld[i].first << ", " << cld[i].second << ")" << endl;
    // }
    // cout << endl;

    // Simulation start: M iterations.
    for (int iter = 0; iter < M; iter ++)
    {
        // 1. move cloud.
        for (unsigned int i = 0; i < cld.size (); i++) {
            int d_i = B[iter].d;    //cout << "d_i: " << d_i <<endl;
            int s_i = B[iter].s;    //cout << "s_i: " << s_i <<endl;
            // index handling!
            cld[i].first = (cld[i].first + dr[d_i] * s_i + N*30) % N;
            cld[i].second = (cld[i].second + dc[d_i] * s_i + N*30) % N;
            if (cld[i].first == 0) cld[i].first = N;
            if (cld[i].second == 0) cld[i].second = N;
        }
        // [DEBUG] - cld position
        // for (unsigned int i = 0; i < cld.size (); i++) {
        //     cout << "(" << cld[i].first << ", " << cld[i].second << ")" << endl;
        // }
        // cout << endl;
        // print_debug ();

        // 2. rain fall.
        for (unsigned int i = 0; i < cld.size (); i++) {
            int r = cld[i].first;
            int c = cld[i].second;
            A[r][c] ++;
        }
        // print_debug ();

        // INIT current cloud map info!
        fill (&mark[0][0], &mark[N][N+1], false);
        // 4. water copy magic.
        for (unsigned int i = 0; i < cld.size (); i++) {
            int r = cld[i].first;
            int c = cld[i].second;
            int cnt = 0;
            // for each diagonal direction.
            for (int j = 1; j <= 4; j++) {
                int nr = r + ddr[j];
                int nc = c + ddc[j];
                if (1 <= nr && nr <= N && 1 <= nc && nc <= N) {
                    if (A[nr][nc] > 0) cnt ++;
                }
            }
            // cout << "(" << r << ", " << c << ")" << endl;
            A[r][c] += cnt;
            mark[r][c] = true;      // UPDATE current cloud map info!
        }
        // print_debug ();

        // INIT current cloud cld vector!
        cld.clear ();
        // 5. cloud generation.
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (mark[i][j] == false && A[i][j] >= 2) {
                    cld.push_back (make_pair (i, j));       // UPDATE current cld vector!
                    A[i][j] -= 2;
                }
            }
        }
        // print_debug ();
        // [DEBUG] - cld position
        // for (unsigned int i = 0; i < cld.size (); i++) {
        //     cout << "(" << cld[i].first << ", " << cld[i].second << ")" << endl;
        // }
        // cout << endl;
    }

    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j ++) {
            result += A[i][j];
        }
    }
    cout << result << '\n';
    return 0;
}