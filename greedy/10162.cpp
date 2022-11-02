// 전자레인지

#include <iostream>
using namespace std;

int T;

int main(void)
{
    cin >> T;

    if (T % 10 != 0) {
        cout << "-1\n";
        return 0;
    }

    cout << T / 300 << ' '; T = T % 300;
    cout << T / 60 << ' ';  T = T % 60;
    cout << T / 10 << '\n';

    return 0;
}