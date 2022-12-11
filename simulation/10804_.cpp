// Written by Raphael on 2022-12-11-Sun.
#include <iostream>
#include <algorithm>    // for reverse ().
using namespace std;

int main (void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // index: place, value: card
    int card[21] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20};
    int a, b;

    for (int i = 0; i < 10; i++)
    {
        cin >> a >> b;
        // for (int j = 0; j < (b - a) / 2 + 1; j++)
        // {
        //     int tmp = card[a + j];
        //     card[a + j] = card[b - j];
        //     card[b - j] = tmp;
        // }

        reverse (card + a, card + b + 1);       // array access using pointer stride.
    }

    for (int i = 1; i <= 20; i++)
        cout << card[i] << ' ';
    cout << '\n';

    return 0;
}