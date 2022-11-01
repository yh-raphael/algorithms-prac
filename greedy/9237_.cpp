// 이장님 초대

#define onlycc ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N;
vector<int> V;

int main(void)
{
    onlycc;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int input;
        cin >> input;
        V.push_back(input);
    }
    sort (V.rbegin(), V.rend());

    int re = 0;
    int tmp;
    for (int i = 0; i < N; i++)
    {
        tmp = V[i] + i + 2;
        if (tmp > re)
            re = tmp;
    }

    cout << re;
    return 0;
}