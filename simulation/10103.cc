#include <iostream>

using namespace std;

int main (void)
{
    ios_base::sync_with_stdio (0);
    cin.tie (0); cout.tie (0);

    int N; cin >> N;

    int A, B;
    int result_A = 100, result_B = 100;
    while (N --)
    {
        cin >> A >> B;
        if (A == B)
            continue;
        else if (A > B)
        {
            result_B -= A;
        }
        else if (A < B)
        {
            result_A -= B;
        }
    }

    cout << result_A << '\n' << result_B << '\n';

    return 0;
}