#include <iostream>
#include <climits>      // LONG_MIN, LONG_MAX, INT_MIN, INT_MAX
using namespace std;

int N;
long A[101];
int OP[4];

long max_val = LONG_MIN;
long min_val = LONG_MAX;

void solve (long head, int index)
{
    if (index == N) {
        if (head > max_val)
            max_val = head;
        if (head < min_val)
            min_val = head;
        return;
    }

    long result = 0;
    for (int i = 0; i < 4; i++)
    {
        if (OP[i] == 0) continue;
        OP[i]--;
        if (i == 0) {
            result = head + A[index + 1];
            solve (result, index + 1);
        }
        else if (i == 1) {
            result = head - A[index + 1];
            solve (result, index + 1);
        }
        else if (i == 2) {
            result = head * A[index + 1];
            solve (result, index + 1);
        }
        else if (i == 3) {
            result = head / A[index + 1];
            solve (result, index + 1);
        }
        OP[i]++;
    }
}

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL); cout.tie (NULL);
    
    cin >> N;
    // A[1], A[2], ... , A[N]
    for (int i = 1; i <= N; i++)
        cin >> A[i];
    // OP[0], OP[1], ... , OP[3]
    for (int i = 0; i < 4; i++)
        cin >> OP[i];

    solve (A[1], 1);

    cout << max_val << '\n';
    cout << min_val << '\n';
    return 0;
}