// Written by Raphael on 2022-01-03-Tue.
#include <iostream>

using namespace std;

int bck [101];

int main (void)
{
    ios_base::sync_with_stdio (0);
    cin.tie (NULL); cout.tie (NULL);

    int M, N, A, B;

    for (int i = 0; i < 101; i++)
        bck [i] = i;

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> A >> B;

        int tmp = bck [A];
        bck [A] = bck [B];
        bck [B] = tmp;
    }

    for (int i = 1; i <= N; i++)
        cout << bck [i] << ' ';
    cout << '\n';

    return 0;
}