#include <iostream>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio (0);
    cin.tie (0); cout.tie (0);

    int L; cin >> L;
    int *cake = new int[L + 1];         // index: piece.

    int N; cin >> N;
    int *num_cake = new int[N + 1];     // index: person.

    // allocate cake pieces.
    int max_exp = 0;
    int person_exp = 0;
    for (int j = 1; j <= N; j++)
    {
        int P,K;
        cin >> P >> K;
        for (int i = P; i <= K; i++)
        {
            if (cake[i] == 0)
                cake[i] = j;
        }
        if (max_exp < (K - P + 1))
        {
            max_exp = K - P + 1;
            person_exp = j;
        }
    }

    // aggregate num of pieces for each person.
    for (int i = 0; i < L + 1; i++)
    {
        num_cake [cake[i]] ++;
    }

    // who the most?
    int max_act = 0;
    int person_act = 0;
    for (int i = 1; i <= N; i++)
    {
        if (max_act < num_cake[i])
        {
            max_act = num_cake[i];
            person_act = i;
        }
    }

    cout << person_exp << '\n';
    cout << person_act << '\n';
    return 0;
}