#include <iostream>
#include <vector>       // vector <pair <int, int> >, num_count.push_back ().
#include <utility>      // make_pair ((cnt[n], n)).
#include <algorithm>    // sort (num_count.begin (), num_count.end ()).
using namespace std;

int arr[101][101];
int r, c, k;

int main (void)
{
    cin >> r >> c >> k;
    for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
            cin >> arr[i][j];

    int r_size = 3;
    int c_size = 3;
    int t = 0;
    for ( ; t <= 100; t++)
    {
        // Test.
        if (arr[r][c] == k)
            break;

        // R-operation.
        if (r_size >= c_size) {
            // for each row.
            for (int i = 1; i <= r_size; i++)
            {
                vector <pair <int, int> > num_count;
                num_count.clear ();
                int cnt[101] = { 0, };
                // count.
                for (int j = 1; j <= c_size; j++)
                {
                    cnt[arr[i][j]] ++;
                }
                // save as pair.
                for (int n = 1; n <= 100; n++)
                {
                    if (cnt[n] > 0) {
                        num_count.push_back (make_pair (cnt[n], n));
                    }
                }
                // sort pairs.
                sort (num_count.begin (), num_count.end ());
                // overwrite pairs to arr.
                int col_idx = 1;
                for (unsigned int n = 0; n < num_count.size (); n++)
                {
                    if (col_idx > 100)
                        break;
                    arr[i][col_idx ++] = num_count[n].second;
                    arr[i][col_idx ++] = num_count[n].first;
                }
                // update max col size.
                c_size = max (c_size, col_idx - 1);
                // pad edge with zero.
                for ( ; col_idx <= 100; col_idx ++)
                {
                    arr[i][col_idx] = 0;
                }
            }// for each row.
        }
        // C-operation.
        else {
            // for each column.
            for (int j = 1; j <= c_size; j++)
            {
                vector <pair <int, int> > num_count;
                num_count.clear ();
                int cnt[101] = { 0, };
                // count.
                for (int i = 1; i <= r_size; i++)
                {
                    cnt[arr[i][j]] ++;
                }
                // save as pair.
                for (int n = 1; n <= 100; n++)
                {
                    if (cnt[n] > 0) {
                        num_count.push_back (make_pair (cnt[n], n));
                    }
                }
                // sort pairs.
                sort (num_count.begin (), num_count.end ());
                // overwrite pairs to arr.
                int row_idx = 1;
                for (unsigned int n = 0; n < num_count.size (); n++)
                {
                    if (row_idx > 100)
                        break;
                    arr[row_idx ++][j] = num_count[n].second;
                    arr[row_idx ++][j] = num_count[n].first;
                }
                // update max col size.
                r_size = max (r_size, row_idx - 1);
                // pad edge with zero.
                for ( ; row_idx <= 100; row_idx ++)
                {
                    arr[row_idx][j] = 0;
                }
            }// for each column.
        }

        // [DEBUG]
        // cout << endl;
        // for (int i = 1; i <= r_size; i++) {
        //     for (int j = 1; j <= c_size; j++) {
        //         cout << arr[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
    }

    if (t > 100)
        cout << -1 << '\n';
    else
        cout << t << '\n';
    return 0;
}