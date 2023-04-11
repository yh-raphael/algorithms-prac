#include <iostream>
using namespace std;
int N, Q;
int map[1000][1000];    // index: 1~999, 1~999
int ar, ac;

void print_map (void)
{
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j++) {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
}

void find_print_pos (void)
{
    for (int i = 1; i <= N; i ++) {
        for (int j = 1; j <= N; j++) {
            if (map[i][j] == Q) {
                cout << i << ' ' << j << '\n';
                return;
            }
        }
    }
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> Q;

    int item = 1;

    int c_i = N/2 + 1;
    int c_j = c_i;
    map[c_i][c_j] = item ++;
    
    int dr[4] = {-1,0,1,0};     // 북,동,남,서
    int dc[4] = {0,1,0,-1};
    int cnt = 1;
    int dir = -1;
    int r = c_i;
    int c = c_j;

    while (true)
    {
        dir = (dir + 1) % 4;
        for (int i = 0; i < cnt; i++){
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            map[nr][nc] = item ++;

            r = nr;
            c = nc;

            if (item == (N * N + 1)) break;
        }
        if (item == (N * N + 1)) break;

        dir = (dir + 1) % 4;
        for (int i = 0; i < cnt; i++){
            int nr = r + dr[dir];
            int nc = c + dc[dir];
            map[nr][nc] = item ++;

            r = nr;
            c = nc;
        }

        cnt ++;
    }
    print_map();
    find_print_pos ();
    return 0;
}