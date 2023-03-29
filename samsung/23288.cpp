#include <iostream>
#include <queue>        // Queue <pair <int, int> > Q, Q.push (make_pair (rr, cc)), Q.front ().first, Q.pop ().
#include <utility>      // make_pair (nr, nc).
#include <cstring>      // memset (check, false, 21*21 * sizeof (bool)), memset (check, false, sizeof (check)).
using namespace std;

int N, M, K;
int map[21][21] = { 0, };
bool check[21][21] = { false, };

int dr[4] = {0, 1, 0, -1};  // 0: east, 1: south, 2: west, 3: north.
int dc[4] = {1, 0, -1, 0};  // 0: east, 1: south, 2: west, 3: north.

int dice[7] = { 0, 1, 2, 3, 4, 5, 6 };
int dir = 0;        // 0: east, 1: south, 2: west, 3: north.
int cur_r = 1;
int cur_c = 1;

void print_debug (void)
{
    cout << endl;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
}

void roll_dice (int d)
{
    int v1, v2, v3, v4, v5, v6;     // 이전의 dice 정보 임시 저장.
    v1 = dice[1]; v2 = dice[2]; v3 = dice[3];
    v4 = dice[4]; v5 = dice[5]; v6 = dice[6];

    if (d == 0) {         // east.
        dice[3] = v1;
        dice[1] = v4;
        dice[4] = v6;
        dice[6] = v3;
    }
    else if (d == 1) {    // south.
        dice[1] = v2;
        dice[2] = v6;
        dice[5] = v1;
        dice[6] = v5;
    }
    else if (d == 2) {    // west.
        dice[1] = v3;
        dice[3] = v6;
        dice[4] = v1;
        dice[6] = v4;
    }
    else if (d == 3) {    // north.
        dice[1] = v5;
        dice[2] = v1;
        dice[5] = v6;
        dice[6] = v2;
    }
}

int bfs (int rr, int cc)
{
    int cnt = 0;
    queue <pair <int, int> > Q;

    Q.push (make_pair (rr, cc));
    check[rr][cc] = true;
    cnt ++; //cout << rr << ", " << cc << endl;

    while (!Q.empty ())
    {
        int r = Q.front ().first;
        int c = Q.front ().second;
        Q.pop ();

        for (int i = 0; i < 4; i++)
        {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            // boundary check!
            if (nr < 1 || nr > N || nc < 1 || nc > M) continue;
            // is visited?
            if (check[nr][nc] == true) continue;

            // is same?
            if (map[nr][nc] == map[r][c]) {
                Q.push (make_pair (nr, nc));
                check[nr][nc] = true;
                cnt ++; //cout << nr << ", " << nc << endl;
            }
        }
    }
    return cnt;
}

int main (void)
{
    cin >> N >> M >> K;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
        }
    }

    int score = 0;
    int how_much = 0;
    for (int cnt = K; cnt > 0; cnt --)
    {
        // (1) roll the dice.
        int tmp_r = cur_r + dr[dir];
        int tmp_c = cur_c + dc[dir];
        if (tmp_r < 1 || tmp_r > N || tmp_c < 1 || tmp_c > M) {
            dir = (dir + 2) % 4;
        }

        roll_dice (dir);
        cur_r = cur_r + dr[dir];
        cur_c = cur_c + dc[dir];    //cout << "== cur_r: " << cur_r << ", cur_c: " << cur_c << endl;

        // (2) calculate score.
        memset (check, false, 21*21 * sizeof(bool));
        how_much = bfs (cur_r, cur_c);
        score += map[cur_r][cur_c] * how_much;  //cout << "score: " << score << endl;

        // (3) resolve next direction.
        int A = dice[6];    //cout << "A: " << A << endl;
        int B = map[cur_r][cur_c];  //cout << "B: " << B << endl;
        if (A > B) {
            dir = (dir + 1) % 4;
        }
        else if (A < B) {
            dir = (dir + 3) % 4;
        }   //cout << "dir: " << dir << endl;
    }

    //print_debug ();
    cout << score << '\n';
    return 0;
}