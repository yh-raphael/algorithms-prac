#include <iostream>
using namespace std;

int map[50][50];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
bool check[50][50] = { false, };

int N, M;
int r, c, d;
int cnt = 0;

int main (void)
{
    cin >> N >> M;
    cin >> r >> c >> d;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (i == 0 || i == N-1 || j == 0 || j == M-1) {
                check[i][j] = 1;
            }
            cin >> map[i][j];
            if (map[i][j] == 1) {
                check[i][j] = 1;
            }
        }
    }

    // cout << r << ' ' << c << ' ' << d << endl;
    while (1)
    {
        if (check[r][c] == 0) {
            // clean up!
            check[r][c] = 1;
            cnt ++;
        }
        
        if (check[r-1][c] == 1 && check[r][c-1] == 1 && check[r+1][c] == 1 && check[r][c+1] == 1) {
            int nr = r + dr[(d+2) % 4];
            int nc = c + dc[(d+2) % 4];
            if (map[nr][nc] == 0) {
                // move!!
                r = nr;
                c = nc;
                // cout << r << ' ' << c << ' ' << d << endl;
                continue;
            }
            else {
                // termiate!
                break;
            }
        }
        
        if (check[r-1][c] == 0 || check[r][c-1] == 0 || check[r+1][c] == 0 || check[r][c+1] == 0) {
            // rotate!!!
            d = (d+3) % 4;
            int nr = r + dr[d];
            int nc = c + dc[d];
            if (check[nr][nc] == 0) {
                // move!!
                r = nr;
                c = nc;
                // cout << r << ' ' << c << ' ' << d << endl;
                continue;
            }
        }
    }

    cout << cnt << '\n';
    return 0;
}