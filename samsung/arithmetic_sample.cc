#include <iostream>
#include <climits>
#include <cmath>
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
    cout << LONG_MIN << "\n\n";

    cout << abs(-5) << '\n';
    cout << abs(-5.5) << '\n';
    cout << abs(-12.5) << '\n';
    return 0;
}