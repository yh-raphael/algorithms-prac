#include <iostream>
#include <vector>       // dynamic
using namespace std;

int dy[4] = {0, -1, 0, 1};  // downward
int dx[4] = {1, 0, -1, 0};  // rightward

int map[101][101];      // map[Y][X]
vector <int> direction;
int result = 0;

int N;
int X, Y, D, G;

void count_square ()
{
    for (int i = 0; i < 100; i++)
    {
        for (int j = 0; j < 100; j++)
        {
            if (map[i][j] == 1 && map[i][j+1] == 1 && map[i+1][j] == 1 && map[i+1][j+1] == 1)
                result ++;
        }
    }
}

void elongate_dragon_curve ()
{
    int s = direction.size ();
    for (int i = s - 1; i >= 0; i--)
    {
        int tmp = (direction[i] + 1) % 4;
        Y += dy[tmp];
        X += dx[tmp];
        map[Y][X] = 1;
        direction.push_back (tmp);
        // cout << X << ' ' << Y << endl;
    }
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL); cout.tie (NULL);

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        direction.clear ();
        cin >> X >> Y >> D >> G;

        // start!
        map[Y][X] = 1;
        // cout << X << ' ' << Y << endl;

        // gen 0.
        Y += dy[D];
        X += dx[D];
        map[Y][X] = 1;
        direction.push_back (D);
        // cout << X << ' ' << Y << endl;

        // gen 1 ~ G.
        for (int j = 0; j < G; j++)
            elongate_dragon_curve ();
    }

    count_square ();
    cout << result << '\n';
    return 0;
}