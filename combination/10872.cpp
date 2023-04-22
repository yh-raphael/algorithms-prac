#include <iostream>

using namespace std;

int N;

int do_factorial (int n)
{
    if (n == 0) {
        return 1;
    }
    else if (n == 1) {
        return 1;
    }
    else {
        return n * do_factorial (n - 1);
    }
}

int main (void)
{
    cin >> N;

    int result = do_factorial (N);

    cout << result << '\n';
    return 0;
}