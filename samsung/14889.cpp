#include <iostream>
#include <climits>          // INT_MAX
#include <cmath>            // abs (start - link)
using namespace std;

int N;
int S[21][21];
bool check[21];

int min_val = INT_MAX;

void solve (int cnt, int pos)
{
    if (cnt == (N / 2)) {
        int start = 0;
        int link = 0;

        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (check[i] == true && check[j] == true)
                    start += S[i][j];
                else if (check[i] == false && check[j] == false)
                    link += S[i][j];
            }
        }

        int tmp = abs (start - link);
        if (tmp < min_val)
            min_val = tmp;

        return;
    }

    // Recursion -> back_tracking.
    for (int i = pos; i <= N; i++)
    {
        check[i] = true;
        solve (cnt + 1, i + 1);     // cnt -> depth;
        check[i] = false;
    }
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL); cout.tie (NULL);

    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> S[i][j];
        }
    }
    
    solve (0, 1);   // cnt, pos

    cout << min_val << '\n';
    return 0;
}