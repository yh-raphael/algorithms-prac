#include <iostream>
#include <vector>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // cout.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;

        vector<bool> arr(N + 1, false);   // index 1 -> first room.
        // false: closed, true: open.
        // Round
        for (int i = 1; i <= N; i++)
        {
            // Simulation
            for (int j = i; j <= N; j += i)
            {
                arr[j] = !arr[j];
            }
        }

        int result = 0;
        for (int k = 1; k <= N; k++)
        {
            if (arr[k] == true)
                result ++;
        }

        cout << result << '\n';
    }
    return 0;
}