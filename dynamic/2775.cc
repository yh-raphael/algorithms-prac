// Written by Raphael on 2023-02-06-Mon.
#include <iostream>
using namespace std;

// Recursive
int get_num_ppl (int level, int num)
{
    if (level == 0)
        return num;
    if (num == 1)
        return 1;
    return get_num_ppl (level - 1, num) + get_num_ppl (level, num - 1);
}

int main (void)
{
    // ios_base::sync_with_stdio (0);
    // cin.tie (NULL); cout.tie (NULL);

    int T, K, N;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        cin >> K >> N;
        cout << get_num_ppl (K, N) << '\n';
    }
    return 0;
}