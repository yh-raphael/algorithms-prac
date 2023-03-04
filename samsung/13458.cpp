#include <iostream>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio (false);
    cin.tie (NULL); cout.tie (NULL);

    int N; cin >> N;
    int A[1000001];
    for (int i = 1; i <= N; i ++)
        cin >> A[i];
    int B, C; cin >> B >> C;

    long long result = 0;
    for (int i = 1; i <= N; i++)
    {
        A[i] -= B;
        result += 1;

        if (A[i] == 0 || A[i] < 0)
            continue;
        else {  // Ceiling
            if ((A[i] % C) != 0)
                result += (A[i] / C) + 1;
            else if ((A[i] % C) == 0)
                result += (A[i] / C);
        }
    }

    cout << result << '\n';
    return 0;
}