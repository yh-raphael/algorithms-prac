#include <iostream>
#include <algorithm>
using namespace std;

int N;
int A[100000] = { 0, };

bool binary_search (int target)
{
    int low = 0;
    int high = N - 1;
    int mid;

    bool isHere = 0;
    while (low <= high)
    {
        mid = (low + high) / 2;

        if (A[mid] == target) {
            isHere = 1;
            break;
        }
        else if (A[mid] < target) {
            low = mid + 1;
        }
        else if (target < A[mid]) {
            high = mid - 1;
        }
    }
    return isHere;
}

int main (void)
{
    ios_base::sync_with_stdio (0);
    cin.tie (0); cout.tie (0);

    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    // sort the input items.
    sort (A, A + N);

    int M; cin >> M;
    for (int i = 0; i < M; i++)
    {
        int input; cin >> input;
        bool result = binary_search (input);
        cout << result << '\n';
    }

    return 0;
}