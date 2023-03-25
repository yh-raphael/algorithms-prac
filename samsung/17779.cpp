#include <iostream>
#include <climits>          // INT_MAX
#include <algorithm>        // sort (sum, sum + 6)
using namespace std;

typedef struct _point {
    int x;
    int y;
} point;
point pos[4];

int N;
int map[21][21];
int label[21][21];

int result = INT_MAX;

void print_debug (void)
{
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << label[i][j] << ' ';
        }
        cout << endl;
    }
}

bool can_make_line (int x, int y, int d1, int d2)
{
    if (x + d1 > N      || y - d1 < 1)                          return false;
    if (x + d2 > N      || y + d2 > N)                          return false;
    if (x + d1 + d2 > N || y - d1 + d2 > N || y - d1 + d2 < 1)  return false;

    return true;
}

void calculate (void)
{
    int sum[6] = { 0, };
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            sum[label[i][j]] += map[i][j];
        }
    }
    
    sort (sum, sum + 6);

    int diff = sum[5] - sum[1];     // sum[0]: dummy.
    result = min (result, diff);
}

void label_area (void)
{
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            label[i][j] = 5;
        }
    }

    // area 1.
    int subArea = 0;
    for (int i = 1; i <= pos[1].x; i++) {
        if (i >= pos[0].x) subArea ++;
        for (int j = 1; j <= pos[0].y - subArea; j++) {
            label[i][j] = 1;
        }
    }
    // area 2.
    int addArea = 0;
    for (int i = 1; i <= pos[2].x; i++) {
        if (i > pos[0].x) addArea ++;
        for (int j = pos[0].y + 1 + addArea; j <= N; j++) {
            label[i][j] = 2;
        }
    }
    // area 3.
    subArea = 0;
    for (int i = N; i >= pos[1].x; i--) {
        if (i < pos[3].x) subArea ++;
        for (int j = 1; j < pos[3].y - subArea; j++) {
            label[i][j] = 3;
        }
    }
    // area 4.
    addArea = 0;
    for (int i = N; i > pos[2].x; i--) {
        if (i <= pos[3].x) addArea ++;
        for (int j = pos[3].y + addArea; j <= N; j++) {
            label[i][j] = 4;
        }
    }

    calculate ();
}

int main (void)
{
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }

    // brute_force.
    for (int i = 1; i <= N; i++)
    {
        for (int j = 2; j <= N; j++)
        {
            for (int d1 = 1; d1 <= j-1; d1++)       // d1: 1 ~ current_y
            {
                for (int d2 = 1; d2 <= N-j; d2++)    // d2: current_y ~ N
                {
                    if (can_make_line (i, j, d1, d2) == true) {
                        pos[0].x = i;           pos[0].y = j;
                        pos[1].x = i + d1;      pos[1].y = j - d1;
                        pos[2].x = i + d2;      pos[2].y = j + d2;
                        pos[3].x = i + d1 + d2; pos[3].y = j - d1 + d2;

                        label_area ();
                        // cout << "i: " << i << ", j: " << j << ", d1: " << d1 << ", d2: " << d2 << endl;
                        // print_debug ();
                    }
                }
            }
        }
    }

    cout << result << '\n';
    return 0;
}