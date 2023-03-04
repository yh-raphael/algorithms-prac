#include <iostream>
#include <climits>          // INT_MAX
#include <cmath>            // abs (start - link)
using namespace std;

#include <vector>

int N;
int S[21][21];
bool check[21];

int min_val = INT_MAX;

void solve (int cnt, int pos)
{
    if (cnt == (N / 2)) {
        int start = 0;
        int link = 0;

        vector <int> start_member;
        vector <int> link_member;
        for (int i = 1; i <= N; i++)
        {
            if (check[i] == true)
                start_member.push_back (i);
            else if (check[i] == false)
                link_member.push_back (i);
        }

        // vector index: starts at '0'!
        for (int i = 0; i < N/2; i++)
        {
            for (int j = 0; j < N/2; j++)
            {
                start += S[start_member[i]][start_member[j]];
                link += S[link_member[i]][link_member[j]];
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