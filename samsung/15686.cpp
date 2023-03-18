#include <iostream>
#include <vector>       // selected[i].push_back (), selected[i].pop_back ().
#include <utility>      // make_pair ().
#include <cmath>        // abs ().
#include <algorithm>    // min ().
#include <climits>      // INT_MAX.
using namespace std;

int N, M;
int map[51][51] = { 0, };

vector <pair <int, int> > houses;
vector <pair <int, int> > chickens;

vector <pair <int, int> > selected;     // max of ckickens: 13, 1 <= M <= 13
bool check[13] = { false, };

int result = INT_MAX;

// [DEBUG]
void print ()
{
    cout << endl << N << ' ' << M << endl;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cout << map[i][j] << ' ';
        }
        cout << endl;
    }
}

int calculate_distance (pair <int, int> a, pair <int, int> b)
{
    return abs(a.first - b.first) + abs (a.second - b.second);
}

void compare_distance ()
{
    int sum = 0;
    // for each house.
    for (unsigned int i = 0; i < houses.size (); i++)
    {
        // resolve the min distance.
        int min_per_house = INT_MAX;
        for (unsigned int j = 0; j < selected.size (); j++)
        {
            min_per_house = min ( min_per_house, calculate_distance (houses[i], selected[j]) );
        }
        sum += min_per_house;
    }
    // global update.
    result = min (result, sum);
}

void make_combination (int x, int m)    // m: recursion count.
{
    // end of recursion.
    if (m == M) {
        compare_distance ();
        // cout << endl;
        // for (unsigned int i = 0; i < selected.size (); i++) {
        //     cout << selected[i].first << ", " << selected[i].second << endl;
        // }
        return;
    }
    for (unsigned int i = x; i < chickens.size (); i++)     // i = 0 으로 선언하면 시간 초과1!! (중복 서치)
    {
        if (check[i] == true) {
            continue;
        }
        check[i] = true;
        selected.push_back (make_pair (chickens[i].first, chickens[i].second));

        // do recursion!
        make_combination (i, m + 1);

        check[i] = false;
        selected.pop_back ();
    }
}

int main (void)
{
    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> map[i][j];
            if (map[i][j] == 1) {
                houses.push_back (make_pair (i, j));
            }
            else if (map[i][j] == 2) {
                chickens.push_back (make_pair (i, j));
            }
        }
    }

    make_combination (0, 0);
    
    cout << result << endl;
    return 0;
}