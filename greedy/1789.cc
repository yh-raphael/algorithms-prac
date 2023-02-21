// ** Problem semantic **: when is the point? 2023-02-22-Wed.
#include <iostream>
using namespace std;

int main (void)
{
    long N; cin >> N;
    long result = 0;

    long cur = 0;
    for (int i = 1; ; i++)
    {
        cur += i;
        if (cur > N) {
            result = i - 1;
            break;
        }
    }

    cout << result << '\n';
    return 0;
}