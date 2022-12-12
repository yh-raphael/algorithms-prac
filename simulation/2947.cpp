// Written by Raphael on 2022-12-12-Mon.
#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio (0);
    cin.tie (0); cout.tie (0);

    // int namu[6] = {0, };    // Initialize all to 0.
    // int wannabe[6] = {0, 1, 2, 3, 4, 5};

    array <int, 6> namu = {0, };  // Initialize all to 0.
    array <int, 6> wannabe = {0, 1, 2, 3, 4, 5};

    cin >> namu[1] >> namu[2] >> namu[3] >> namu[4] >> namu[5];

    while (namu != wannabe)
    {
        if (namu[1] > namu[2]) {
            swap (namu[1], namu[2]);
            // Print block.
            for (int i = 1; i < 6; i++)
                cout << namu[i] << ' ';
            cout << '\n';
        }

        if (namu[2] > namu[3]) {
            swap (namu[2], namu[3]);
            // Print block.
            for (int i = 1; i < 6; i++)
                cout << namu[i] << ' ';
            cout << '\n';
        }

        if (namu[3] > namu[4]) {
            swap (namu[3], namu[4]);
            // Print block.
            for (int i = 1; i < 6; i++)
                cout << namu[i] << ' ';
            cout << '\n';
        }

        if (namu[4] > namu[5]) {
            swap (namu[4], namu[5]);
            // Print block.
            for (int i = 1; i < 6; i++)
                cout << namu[i] << ' ';
            cout << '\n';
        }

        if (namu[1] > namu[2]) {
            swap (namu[1], namu[2]);
            // Print block.
            for (int i = 1; i < 6; i++)
                cout << namu[i] << ' ';
            cout << '\n';
        }
    }

    return 0;
}