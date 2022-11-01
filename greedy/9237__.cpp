// 이장님 초대

#define onlycc ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_LEN 100000
int N;
int T[MAX_LEN];

int main(void)
{
    onlycc;

    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> T[i];
    }
    sort (T, T + N, greater<int>());

    int re = 0;
    for (int i = 0; i < N; i++)
    {
        T[i] += i + 2;
        if (T[i] > re)
            re = T[i];
    }

    cout << re << '\n';
    return 0;
}