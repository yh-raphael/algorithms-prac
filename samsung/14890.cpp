#include <iostream>
#include <cstring>      // memcpy ().
#include <cmath>        // abs ().
using namespace std;

int N, L;
int map[101][101] = { 0, };     // horizontal search.
int map_t[101][101] = { 0, };   // vertical search.

void debug_print ()
{
    cout << '\n';
    cout << N << ' ' << L << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << map[i][j] << ' ';
        }
        cout << '\n';
    }
}

// for decrementing level case.
bool project_availability (int r, int c)
{
    int target = map[r][c+1];  //cout << "r: " << r << ", c: " << c << ", target: " << target << endl;
    int count = 0;
    for (int j = c+1; j < N; j++)
    {
        if (map[r][j] == target) {
            count ++;
        }
        else {
            break;
        }
    }
    if (count >= L)
        return true;
    else
        return false;
}

int make_road (void)
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        bool is_available = true;
        int road_count = 1;     // memorizing variable!!!

        for (int j = 0; j < N - 1; j++)
        {
            // same level
            if (map[i][j] == map[i][j+1]) {
                road_count ++;
            }
            // incrementing level: 1 1 2
            else if (map[i][j] + 1 == map[i][j+1]) {
                if (road_count >= L) {
                    road_count = 1; // initialize!!
                }
                else {
                    is_available = false;
                    // cout << "i: " << i << ", j: " << j << ", road_count: " << road_count << endl;
                    break;
                }
            }
            // decrementing level: 2 2 1 1 2 2
            else if (map[i][j] - 1 == map[i][j+1]) {
                if (project_availability (i, j) == true) {
                    j = j + (L - 1);    // '-1' !!
                    road_count = 0;     // start at 0!!
                }
                else {
                    is_available = false;
                    break;
                }
            }
            // level diff: greater than or equal 2
            else if (abs (map[i][j] - map[i][j+1]) >= 2) {
                is_available = false;
                break;
            }
        }
        if (is_available == true) {
            // cout << "row: " << i << endl;
            sum ++;
        }
    }
    return sum;
}

int main (void)
{
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> map[i][j];
            map_t[j][i] = map[i][j];
        }
    }

    int result = 0;
    // horizontal way scan.
    result += make_road ();

    // vertical way scan.
    memcpy (map, map_t, sizeof(int) * 101 * 101);
    result += make_road ();

    cout << result << '\n';
    return 0;
}