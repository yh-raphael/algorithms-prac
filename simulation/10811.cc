// Written by Raphael on 2023-01-19-Thur.
#include <iostream>
#include <vector>       // vector <int> vec;
#include <algorithm>    // reverse (vec.begin () + i, vec.begin () + j + 1);

using namespace std;

int main (void)
{
    int N, M; cin >> N >> M;

    vector <int> vec;   // {0, 1, 2 ... N}
    for (int i = 0; i <= N; i++)
    {
        vec.push_back (i);
    }

    while (M --)
    {
        int i, j; cin >> i >> j;
        reverse (vec.begin () + i, vec.begin () + j + 1);
    }

    for (int k = 1; k <= N; k++)
    {
        cout << vec[k] << ' ';
    }
    cout << '\n';
    return 0;
}