// 이장님 초대

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define MAXLEN  100000
int N;
vector<int> V;

int main(void)
{
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

    printf("%d\n", re);
    return 0;
}