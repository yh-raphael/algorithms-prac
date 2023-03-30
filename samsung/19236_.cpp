#include <iostream>
#include <algorithm>    // swap (map[r][c], map[nr][nc]), result = max (result, sum).
using namespace std;

typedef struct _fish {
    int r;
    int c;
    int dir;
    bool alive;
} fish;

int map[4][4];      // -1: shark, 0: empty, 1~16: prey.
fish flist[17];

// 8 direction diff.
int dr[9] = {9, -1, -1, 0, 1, 1, 1, 0, -1};
int dc[9] = {9, 0, -1, -1, -1, 0, 1, 1, 1};

int result = 0;

void print_map (void)
{
    cout << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << map[i][j] << ' ';
        } cout << endl;
    }
}

void swap_fish (int src_i, int dst_i)
{
    fish tmp = flist[dst_i];

    flist[dst_i].r = flist[src_i].r;
    flist[dst_i].c = flist[src_i].c;

    flist[src_i].r = tmp.r;
    flist[src_i].c = tmp.c;
}

void move_fish (void)
{
    // for each fish in order.
    for (int i = 0; i <= 16; i++)
    {
        // cout << "i:" << i << ", " << flist[i].r << ", " << flist[i].c << ", " << flist[i].dir << ", " << flist[i].alive << endl;
        // liveness check.
        if (flist[i].alive == false) continue;

        // retrieve (r, c, dir) and (nr, nc).
        int r = flist[i].r;
        int c = flist[i].c;
        int dir = flist[i].dir;

        int nr = r + dr[dir];
        int nc = c + dc[dir];
        bool flag = false;

        // boundary check.
        if (0 <= nr && nr <= 3 && 0 <= nc && nc <= 3) {
            // empty box.
            if (map[nr][nc] == 0) {
                flist[i].r = nr;
                flist[i].c = nc;

                map[nr][nc] = i;
                map[r][c] = 0;

                flag = true;
            }
            // other fish is there.
            else if (map[nr][nc] != -1) {
                swap_fish (i, map[nr][nc]);
                swap (map[r][c], map[nr][nc]);
                flag = true;
            }
        }

        // cannot move toward current "direction".
        if (flag == false) {
            int nDir = dir + 1;
            if (nDir == 9) nDir = 1;
            int nr = r + dr[nDir];
            int nc = c + dc[nDir];
            
            // 1 바퀴 다 돌 때까지! ** good idea **
            while (nDir != dir)
            {
                //cout << "nDir: " << nDir << ", map[nr][nc]: " << map[nr][nc] << endl;
                // boundary check.
                if (0 <= nr && nr <= 3 && 0 <= nc && nc <= 3) {
                    // empty box.
                    if (map[nr][nc] == 0) {
                        flist[i].r = nr;
                        flist[i].c = nc;

                        map[nr][nc] = i;
                        map[r][c] = 0;

                        flist[i].dir = nDir;
                        break;
                    }
                    // other fish is there.
                    else if (map[nr][nc] != -1) {
                        swap_fish (i, map[nr][nc]);
                        swap (map[r][c], map[nr][nc]);
                        flist[i].dir = nDir;
                        break;
                    }
                }

                // cannot move toward "nDir".
                nDir ++;
                if (nDir == 9) nDir = 1;
                nr = r + dr[nDir];
                nc = c + dc[nDir];
            } // nDir iteration loop.
        } // nDir search branch.
        // print_map ();
    } // fish iteration loop.
}

void copy_state (int map_dst[][4], int map_src[][4], fish flist_dst[], fish flist_src[])
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            map_dst[i][j] = map_src[i][j];
        }
    }
    for (int i = 1; i <= 16; i++)
    {
        flist_dst[i] = flist_src[i];
    }
}

void move_shark (int r, int c, int nr, int nc, int prey_num, bool flag)
{
    // 살아 있는 친구면 eat!
    if (flag == true) {
        map[r][c] = 0;
        map[nr][nc] = -1;
        flist[prey_num].alive = false;
    }
    // 죽어 있었으면 다시 살리는 복구.
    else {
        map[r][c] = -1;
        map[nr][nc] = prey_num;
        flist[prey_num].alive = true;
    }
}

void dfs (int s_r, int s_c, int s_dir, int sum)
{
    // result = max (result, sum);      // 여기여도 되지만, 매번 중간 leaf일 때도 다 해주게 됨.

    int map_copied[4][4];
    fish flist_copied[17];
    copy_state (map_copied, map, flist_copied, flist);  // ***

    // move fish.
    move_fish ();

    // move shark.
    for (int i = 1; i <= 3; i++)
    {
        int nr = s_r + dr[s_dir] * i;
        int nc = s_c + dc[s_dir] * i;
        // boundary check.
        if (0 <= nr && nr <= 3 && 0 <= nc && nc <= 3) {
            if (map[nr][nc] == 0) continue;     // 없으면 집으로 가야 됨.

            int prey_num = map[nr][nc];
            int nDir = flist[prey_num].dir;

            move_shark (s_r, s_c, nr, nc, prey_num, true);      // @@@
            dfs (nr, nc, nDir, sum + prey_num);                 // *** do the dfs recursion!
            move_shark (s_r, s_c, nr, nc, prey_num, false);     // @@@
        }

        result = max (result, sum);     // 여기서 계산하면, leaf node에서만 계산하게 됨!
    }

    copy_state (map, map_copied, flist, flist_copied);  // ***
}

int main (void)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int a, b; cin >> a >> b;
            map[i][j] = a;
            flist[a].r = i; flist[a].c = j;
            flist[a].dir = b; flist[a].alive = true;
        }
    }

    // Init.
    int num = map[0][0];
    int dir = flist[num].dir;
    flist[num].alive = false;
    map[0][0] = -1;

    // dfs start!
    dfs (0, 0, dir, num);

    cout << result << '\n';
    return 0;
}