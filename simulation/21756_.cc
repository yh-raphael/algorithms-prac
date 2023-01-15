// So fancy implementation!!!
#include <iostream>
using namespace std;

int main ()
{
    int N; cin >> N;
    int n = N;
    int result = 1;

    // Erase and Record!
    while (1 < n)
    {
        n /= 2;
        result *= 2;
    }

    cout << result << '\n';
    return 0;
}