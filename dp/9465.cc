// Written by Raphael on 2023-02-07-Tue.
#include <iostream>
using namespace std;    // max ();

int main (void)
{
    ios_base::sync_with_stdio (0);
    cin.tie (NULL); cout.tie (NULL);

    int T; cin >> T;
    for (int i = 0; i < T; i++)
    {
        int N; cin >> N;
        int arr1[100001] = {0,}; int arr2[100001] = {0,};
        int dp1[100001] = {0,}; int dp2[100001] = {0,};

        for (int j = 1; j <= N; j++)
            cin >> arr1[j];
        for (int j = 1; j <= N; j++)
            cin >> arr2[j];
        
        // for (int j = 1; j <= N; j++)
        //     cout << arr1[j] << ' ';
        // cout << '\n';
        // for (int j = 1; j <= N; j++)
        //     cout << arr2[j] << ' ';
        // cout << '\n';

        for (int j = 1; j <= N; j++)
        {
            if (j == 1) {
                dp1[j] = arr1[j];
                dp2[j] = arr2[j];
            }
            else if (j == 2) {
                dp1[j] = arr1[j] + arr2[j - 1];
                dp2[j] = arr2[j] + arr1[j - 1];
            }
            else {
                dp1[j] = arr1[j] + max (dp2[j - 1], dp2[j - 2]);
                dp2[j] = arr2[j] + max (dp1[j - 1], dp1[j - 2]);
            }
        }

        // for (int j = 1; j <= N; j++)
        //     cout << dp1[j] << ' ';
        // cout << '\n';
        // for (int j = 1; j <= N; j++)
        //     cout << dp2[j] << ' ';
        // cout << '\n';

        cout << max (dp1[N], dp2[N]) << '\n';
    }
    return 0;
}