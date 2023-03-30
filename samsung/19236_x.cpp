#include <iostream>
#include <cstring>      // memcpy (map, map_copied, sizeof(map)).
#include <vector>
#include <utility>
using namespace std;

// [1] shark info.
int shark_r, shark_c;
int shark_dir;

// [2] prey info.
vector <pair <int, int> > prey_v (17, make_pair (-1, -1));     // index: fish_num, element: fish_pos (r, c) / (-1, -1): eaten!

// [3] map info.
typedef struct _fish {
    int num;    // -1: blank!, 0: shark, 1~16: prey.
    int dir;    // -1: blank!, 0: shark, 1: N, 2: NW, 3: W, 4:SW, 5: S, 6: SE, 7: E, 8: NE.
} fish;
fish map[4][4];
fish map_copied[4][4];

// 8 direction diff.
int dr[9] = {9, -1, -1, 0, 1, 1, 1, 0, -1};
int dc[9] = {9, 0, -1, -1, -1, 0, 1, 1, 1};

void solve (void)
{
    // init.
    memcpy (map, map_copied, sizeof(map));

    // start -> shark setting.
    shark_r = 0; shark_c = 0;                       
    shark_dir = map[0][0].dir;                      // [1] move.
    prey_v[map[0][0].num] = make_pair (-1, -1);     // [2] eat.
    map[0][0].num = 0; map[0][0].dir = 0;           // [3] map update.
    
    while (1)
    {
        for (int i = 1; i <= 16; i++)
        {
            // already eaten.
            if (prey_v[i] == make_pair (-1, -1)) continue;

            // prey_v[i].first + dr[ map[prey_v[i].first][prey_v[i].second].dir ];
            // prey_v[i].second + dc[ map[prey_v[i].first][prey_v[i].second].dir ];
            // 여기서 부터 장렬히 전사.. 이렇게 complexity가 높게 짜서는 developer 입장에서 더는 못함..
        }
    }
}

int main (void)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> map[i][j].num >> map[i][j].dir;
            prey_v[map[i][j].num] = make_pair (i, j);
        }
    }
    memcpy (map_copied, map, sizeof(map));


    // solve ();

    // [DEBUG]-prey_v.
    cout << endl;
    for (unsigned int i = 0; i <= 16; i++)
    {
        cout << "i: " << i << ", (" << prey_v[i].first << ", " << prey_v[i].second << ") \n";
    } cout << endl;
    // [DEBUG]-input.
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cout << "(" << map[i][j].num << ", " << map[i][j].dir << ") ";
        } cout << endl;
    } cout << endl;
    
    return 0;
}