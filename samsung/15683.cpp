#include <iostream>
#include <vector>       // vector <pair <int, int> > cam_pos
#include <utility>      // make_pair (i, j)
using namespace std;

int N, M;       // Height, Width.
int map[9][9];  // ongoing basis.
vector <pair <int, int> > cam_pos;
vector <int> cam_type;
int result = 81;
int rot_num[6] = {0, 4, 2, 4, 4, 1};    // dummy, cam_1 ~ cam_5.

void print_map ()
{
    cout << endl;
    cout << N << ' ' << M << endl;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
    
    // cout << endl;
    // for (unsigned int i = 0; i < cam_pos.size (); i++) {
    //     cout << cam_pos[i].first << ", " << cam_pos[i].second << '\n';
    // }
    // for (unsigned int i = 0; i < cam_type.size (); i++) {
    //     cout << cam_type[i] << '\n';
    // }
}

void copy_map (int backup[9][9], int origin[9][9])
{
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            backup[i][j] = origin[i][j];
        }
    } 
    // cout << "copy_map!\n";
}

int count_free_space ()
{
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (map[i][j] == 0)
                cnt ++;
        }
    }
    // cout << "cnt: " << cnt << '\n';
    return cnt;
}

// turn on the cam.
void check_map (int r, int c, int dir)
{
    if (dir == 0) {
        for (int walker = c + 1; walker <= M; walker ++)
        {
            if (map[r][walker] == 6)
                return;
            map[r][walker] = 7;
        }
    }
    else if (dir == 1) {
        for (int walker = r + 1; walker <= N; walker ++)
        {
            if (map[walker][c] == 6)
                return;
            map[walker][c] = 7;
        }
    }
    else if (dir == 2) {
        for (int walker = c - 1; walker >= 1; walker --)
        {
            if (map[r][walker] == 6)
                return;
            map[r][walker] = 7;
        }        
    }
    else if (dir == 3) {
        for (int walker = r - 1; walker >= 1; walker --)
        {
            if (map[walker][c] == 6)
                return;
            map[walker][c] = 7;
        }
    }
}

void solve (unsigned int i)
{
    // recursion break.
    if (i == cam_type.size ()) {
        // print_map ();
        int num = count_free_space ();
        if (num < result)
            result = num;   // global variable update.
        return;
    }

    int r = cam_pos[i].first;
    int c = cam_pos[i].second;
    int ct = cam_type[i];
    // for each case. { 4, 2, 4, 4, 1}
    int copied[9][9] = {0,}; ;
    for (int j = 0; j < rot_num[ct]; j++)
    {
        // save 
        copy_map (copied, map);
        // turn on the cam.
        if (ct == 1) {
            check_map (r, c, j);
        }
        else if (ct == 2) {
            check_map (r, c, j);
            check_map (r, c, (j+2) % 4);
        }
        else if (ct == 3) {
            check_map (r, c, j);
            check_map (r, c, (j+1)%4);
        }
        else if (ct == 4) {
            check_map (r, c, j);
            check_map (r, c, (j+1)%4);
            check_map (r, c, (j+2)%4);
        }
        else if (ct == 5) {
            check_map (r, c, j);
            check_map (r, c, j+1);
            check_map (r, c, j+2);
            check_map (r, c, j+3);
        }
        // do the recursion.
        solve (i + 1);
        // resotre.
        copy_map (map, copied);
    }
}

int main (void)
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> map[i][j];
            if (1 <= map[i][j] && map[i][j] <= 5) {
                cam_pos.push_back (make_pair (i, j));
                cam_type.push_back (map[i][j]);
            }
        }
    }
    
    // start recursion.
    solve (0);

    cout << result << '\n';
    return 0;
}