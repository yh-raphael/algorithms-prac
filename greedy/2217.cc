// Written by Raphael on 2023-02-07-Tue.
#include <iostream>
#include <algorithm>
using namespace std;

int arr[100001] = {0,};
// long weight[100001] = {0,};

int main (void)
{
    ios_base::sync_with_stdio (0);
    cin.tie (NULL); cout.tie (NULL);
    
    int N; cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    sort (arr + 1, arr + 1 + N, greater <int> ());

    // for (int i = 1; i <= N; i++)
    //     cout << arr[i] << ' ';
    // cout << '\n';

    int best = 0;
    for (int i = 1; i <= N; i++)
    {
        arr[i] = arr[i] * i;
        if (arr[i] > best)
            best = arr[i];
    }

    // for (int i = 1; i <= N; i++)
    //     cout << weight[i] << ' ';
    // cout << '\n';

    cout << best << '\n';
    
    return 0;
}