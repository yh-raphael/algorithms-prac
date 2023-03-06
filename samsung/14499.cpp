// dice mananging, direction handling, (dx,dy)
#include <iostream>
using namespace std;

int map[21][21];
int CMD[1002];
int dice[7] = { 0, };

int N, M;
int x, y;
int K;

void roll_dice (int dir)
{
    int v1, v2, v3, v4, v5, v6;
    v1 = dice[1]; v2 = dice[2]; v3 = dice[3];
    v4 = dice[4]; v5 = dice[5]; v6 = dice[6];

    if (dir == 1) {     // right
        dice[1] = v4;
        dice[3] = v1;
        dice[4] = v6;
        dice[6] = v3;
    }
    else if (dir == 2) {     // left
        dice[1] = v3;
        dice[3] = v6;
        dice[4] = v1;
        dice[6] = v4;
    }
    else if (dir == 3) {     // up
        dice[1] = v5;
        dice[2] = v1;
        dice[5] = v6;
        dice[6] = v2;
    }
    else if (dir == 4) {     // down
        dice[1] = v2;
        dice[2] = v6;
        dice[5] = v1;
        dice[6] = v5;
    }
}

void play (void)
{
    int dx[4] = {0, 0, -1, 1};      // downward direction.
    int dy[4] = {1, -1, 0, 0};      // rightward direction.

    for (int i = 0; i < K; i++)
    {
        int nx = x + dx[CMD[i] - 1];
        int ny = y + dy[CMD[i] - 1];

        // boundary check.
        if (nx < 0 || nx >= N || ny < 0 || ny >= M)
            continue;

        // dice update.
        roll_dice (CMD[i]);

        // map update.
        if (map[nx][ny] == 0)
            map[nx][ny] = dice[6];
        else {
            dice[6] = map[nx][ny];
            map[nx][ny] = 0;
        }

        // dice current position update.
        x = nx; y = ny;

        cout << dice[1] << '\n';
    }
}

int main (void)
{
    cin >> N >> M;
    cin >> x >> y;
    cin >> K;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    for (int i = 0; i < K; i++) {
        cin >> CMD[i];
    }

    play ();

    return 0;
}