// Written by Raphael on 2023-02-06-Mon.
#include <iostream>
using namespace std;

// int fibonacci (int num)
// {
//     if (num == 0)
//         return 0;
//     if (num == 1)
//         return 1;
//     return fibonacci (num - 2) + fibonacci (num - 1);
// }

int main (void)
{
    long arr[91] = { 0, };
    int N; cin >> N;
    // cout << fibonacci (N) << '\n';

    arr[0] = 0;
    arr[1] = 1;
    for (int i = 0; i <= N - 2; i++)
    {
        arr[i + 2] = arr[i] + arr[i + 1];
    }

    cout << arr[N] << '\n';
    return 0;
}