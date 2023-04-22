#include <iostream>

using namespace std;

unsigned int N, M;

int main (void)
{
    cin >> N >> M;
    unsigned long long result = 1;
    unsigned long long tmp = 1;
    for (unsigned int i = N; i > N - M; i--) {
        result *= (unsigned long long) i;
        result /= tmp ++;
    }
    cout << result << '\n';
    return 0;
}