// ATM - OS waiting time

#include <iostream>
#include <algorithm>
using namespace std;

int N;
int re = 0;

int main (void)
{
    int arr[1000];

    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    sort(arr, arr + N);

    for (int i = 0; i < N; i++) {
        re += arr[i] * (N - i);
    }

    cout << re << '\n';
    return 0;
}