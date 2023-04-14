#include <iostream>
#include <cstring>
using namespace std;
int N;
int main (void)
{
    cin >> N;
    string a; cin >> a;
    int result = 0;
    for (int i = 0; i < N; i++) {
        result += (char) a[i] - (char) '0';
    }
    cout << result << '\n';
    return 0;
}