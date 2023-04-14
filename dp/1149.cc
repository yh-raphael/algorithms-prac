// Dynamic Point! - overwriting to remember so far record. on 2023-02-24-Fri.
#include <iostream>
#include <algorithm>
using namespace std;

int main (void)
{
    int arr[1000][3] = { 0, };
    int N; cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
    }

    for (int i = 1; i < N; i++)
    {
        arr[i][0] = arr[i][0] + min (arr[i - 1][1], arr[i - 1][2]);
        arr[i][1] = arr[i][1] + min (arr[i - 1][0], arr[i - 1][2]);
        arr[i][2] = arr[i][2] + min (arr[i - 1][0], arr[i - 1][1]);
    }
    int min = arr[N - 1][0];
    for (int i = 1; i < 3; i++)
    {
        if (min > arr[N - 1][i])
            min = arr[N - 1][i];
    }

    cout << min << '\n';
    return 0;
}