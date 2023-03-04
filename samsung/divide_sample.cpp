#include <iostream>
#include <climits>
using namespace std;

int main (void)
{
    int result = (-5) / 1;
    cout << result << '\n';
    result = (-5) / 2;
    cout << result << '\n';
    result = (-5) / 3;
    cout << result << '\n';
    result = (-5) / 5;
    cout << result << "\n\n";

    cout << sizeof (int) << '\n';
    cout << sizeof (long) << '\n';
    cout << sizeof (long long) << "\n\n";

    cout << INT_MAX << '\n';
    cout << INT_MIN << '\n';
    cout << LONG_MAX << '\n';
    cout << LONG_MIN << '\n';
    return 0;
}