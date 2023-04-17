#include <iostream>
using namespace std;

unsigned int T, N, M;

void solve (void)
{
    // int bm = M;
    // int bn1 = N;
    // int bn2 = M-N;

    unsigned long long result = 1;
    unsigned int tmp = 1;

    for (unsigned int term = M; term > N; term --) {
        result *= term;     //cout << result % tmp << endl;
        result /= tmp ++;
    }

    // unsigned long long result2 = 1;
    // unsigned int tmp2 = 1;
    // for (unsigned int term = M; term > M-N; term --) {
    //     result2 *= term;     cout << result2 % tmp2 << endl;
    //     result2 /= tmp2 ++;
    // }
    // cout << result2 << endl;

    cout << result << '\n';
}

int main (void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie (NULL);

    cin >> T;
    for (unsigned int tc = 1; tc <= T; tc++)
    {
        cin >> N >> M;
        solve ();
    }
    return 0;
}